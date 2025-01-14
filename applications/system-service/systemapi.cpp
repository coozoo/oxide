#include "systemapi.h"
#include "appsapi.h"
#include "powerapi.h"

void SystemAPI::PrepareForSleep(bool suspending){
    if(suspending){
        auto path = appsAPI->currentApplication();
        if(path.path() != "/"){
            resumeApp = appsAPI->getApplication(path);
            resumeApp->pause(false);
        }else{
            resumeApp = nullptr;
        }
        drawSleepImage();
        qDebug() << "Suspending...";
        buttonHandler->setEnabled(false);
        releaseSleepInhibitors();
    }else{
        inhibitSleep();
        qDebug() << "Resuming...";
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        if(resumeApp == nullptr){
            resumeApp = appsAPI->getApplication(appsAPI->startupApplication());
        }
        resumeApp->resume();
        buttonHandler->setEnabled(true);
        if(m_autoSleep && powerAPI->chargerState() != PowerAPI::ChargerConnected){
            qDebug() << "Suspend timer re-enabled due to resume";
            suspendTimer.start(m_autoSleep * 60 * 1000);
        }
    }
}
void SystemAPI::setAutoSleep(int autoSleep){
    if(autoSleep < 0 || autoSleep > 10){
        return;
    }
    m_autoSleep = autoSleep;
    if(m_autoSleep && powerAPI->chargerState() != PowerAPI::ChargerConnected){
        suspendTimer.setInterval(m_autoSleep * 60 * 1000);
    }
    settings.setValue("autoSleep", autoSleep);
    settings.sync();
}
void SystemAPI::uninhibitAll(QString name){
    powerOffInhibitors.removeAll(name);
    sleepInhibitors.removeAll(name);
    if(!sleepInhibited() && m_autoSleep && powerAPI->chargerState() != PowerAPI::ChargerConnected && !suspendTimer.isActive()){
        qDebug() << "Suspend timer re-enabled due to uninhibit" << name;
        suspendTimer.start(m_autoSleep * 60 * 1000);
    }
}
void SystemAPI::startSuspendTimer(){
    if(m_autoSleep && powerAPI->chargerState() != PowerAPI::ChargerConnected && !suspendTimer.isActive()){
        qDebug() << "Suspend timer re-enabled due to start Suspend timer";
        suspendTimer.start(m_autoSleep * 60 * 1000);
    }
}
void SystemAPI::activity(){
    auto active = suspendTimer.isActive();
    suspendTimer.stop();
    if(m_autoSleep && powerAPI->chargerState() != PowerAPI::ChargerConnected){
        if(!active){
            qDebug() << "Suspend timer re-enabled due to activity";
        }
        suspendTimer.start(m_autoSleep * 60 * 1000);
    }else if(active){
        qDebug() << "Suspend timer disabled";
    }
}
void SystemAPI::uninhibitSleep(QDBusMessage message) {
    sleepInhibitors.removeAll(message.service());
    if(!sleepInhibited() && m_autoSleep && powerAPI->chargerState() != PowerAPI::ChargerConnected){
        if(!suspendTimer.isActive()){
            qDebug() << "Suspend timer re-enabled due to uninhibit sleep" << message.service();
            suspendTimer.start(m_autoSleep * 60 * 1000);
        }
        releaseSleepInhibitors(true);
    }
}
void SystemAPI::timeout(){
    if(m_autoSleep && powerAPI->chargerState() != PowerAPI::ChargerConnected){
        suspend();
    }
}
