/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -N -p wpa_supplicant.h:wpa_supplicant.cpp fi.w1.wpa_supplicant1.xml
 *
 * qdbusxml2cpp is Copyright (C) 2017 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef WPA_SUPPLICANT_H
#define WPA_SUPPLICANT_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface fi.w1.wpa_supplicant1
 */
class FiW1Wpa_supplicant1Interface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "fi.w1.wpa_supplicant1"; }

public:
    FiW1Wpa_supplicant1Interface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~FiW1Wpa_supplicant1Interface();

    Q_PROPERTY(QString DebugLevel READ debugLevel WRITE setDebugLevel)
    inline QString debugLevel() const
    { return qvariant_cast< QString >(property("DebugLevel")); }
    inline void setDebugLevel(const QString &value)
    { setProperty("DebugLevel", QVariant::fromValue(value)); }

    Q_PROPERTY(bool DebugShowKeys READ debugShowKeys WRITE setDebugShowKeys)
    inline bool debugShowKeys() const
    { return qvariant_cast< bool >(property("DebugShowKeys")); }
    inline void setDebugShowKeys(bool value)
    { setProperty("DebugShowKeys", QVariant::fromValue(value)); }

    Q_PROPERTY(bool DebugTimestamp READ debugTimestamp WRITE setDebugTimestamp)
    inline bool debugTimestamp() const
    { return qvariant_cast< bool >(property("DebugTimestamp")); }
    inline void setDebugTimestamp(bool value)
    { setProperty("DebugTimestamp", QVariant::fromValue(value)); }

    Q_PROPERTY(QStringList EapMethods READ eapMethods)
    inline QStringList eapMethods() const
    { return qvariant_cast< QStringList >(property("EapMethods")); }

    Q_PROPERTY(QList<QDBusObjectPath> Interfaces READ interfaces)
    inline QList<QDBusObjectPath> interfaces() const
    { return qvariant_cast< QList<QDBusObjectPath> >(property("Interfaces")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QDBusObjectPath> CreateInterface(const QVariantMap &args)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(args);
        return asyncCallWithArgumentList(QStringLiteral("CreateInterface"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> GetInterface(const QString &ifname)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(ifname);
        return asyncCallWithArgumentList(QStringLiteral("GetInterface"), argumentList);
    }

    inline QDBusPendingReply<> RemoveInterface(const QDBusObjectPath &path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path);
        return asyncCallWithArgumentList(QStringLiteral("RemoveInterface"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void InterfaceAdded(const QDBusObjectPath &path, const QVariantMap &properties);
    void InterfaceRemoved(const QDBusObjectPath &path);
    void PropertiesChanged(const QVariantMap &properties);
};

/*
 * Proxy class for interface fi.w1.wpa_supplicant1.BSS
 */
class FiW1Wpa_supplicant1BSSInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "fi.w1.wpa_supplicant1.BSS"; }

public:
    FiW1Wpa_supplicant1BSSInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~FiW1Wpa_supplicant1BSSInterface();

    Q_PROPERTY(QByteArray BSSID READ bSSID)
    inline QByteArray bSSID() const
    { return qvariant_cast< QByteArray >(property("BSSID")); }

    Q_PROPERTY(ushort Frequency READ frequency)
    inline ushort frequency() const
    { return qvariant_cast< ushort >(property("Frequency")); }

    Q_PROPERTY(QByteArray IEs READ iEs)
    inline QByteArray iEs() const
    { return qvariant_cast< QByteArray >(property("IEs")); }

    Q_PROPERTY(QString Mode READ mode)
    inline QString mode() const
    { return qvariant_cast< QString >(property("Mode")); }

    Q_PROPERTY(bool Privacy READ privacy)
    inline bool privacy() const
    { return qvariant_cast< bool >(property("Privacy")); }

    Q_PROPERTY(QVariantMap RSN READ rSN)
    inline QVariantMap rSN() const
    { return qvariant_cast< QVariantMap >(property("RSN")); }

    Q_PROPERTY(QList<uint> Rates READ rates)
    inline QList<uint> rates() const
    { return qvariant_cast< QList<uint> >(property("Rates")); }

    Q_PROPERTY(QByteArray SSID READ sSID)
    inline QByteArray sSID() const
    { return qvariant_cast< QByteArray >(property("SSID")); }

    Q_PROPERTY(short Signal READ signal)
    inline short signal() const
    { return qvariant_cast< short >(property("Signal")); }

    Q_PROPERTY(QVariantMap WPA READ wPA)
    inline QVariantMap wPA() const
    { return qvariant_cast< QVariantMap >(property("WPA")); }

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
    void PropertiesChanged(const QVariantMap &properties);
};

/*
 * Proxy class for interface fi.w1.wpa_supplicant1.Interface
 */
class FiW1Wpa_supplicant1InterfaceInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "fi.w1.wpa_supplicant1.Interface"; }

public:
    FiW1Wpa_supplicant1InterfaceInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~FiW1Wpa_supplicant1InterfaceInterface();

    Q_PROPERTY(uint ApScan READ apScan WRITE setApScan)
    inline uint apScan() const
    { return qvariant_cast< uint >(property("ApScan")); }
    inline void setApScan(uint value)
    { setProperty("ApScan", QVariant::fromValue(value)); }

    Q_PROPERTY(uint BSSExpireAge READ bSSExpireAge WRITE setBSSExpireAge)
    inline uint bSSExpireAge() const
    { return qvariant_cast< uint >(property("BSSExpireAge")); }
    inline void setBSSExpireAge(uint value)
    { setProperty("BSSExpireAge", QVariant::fromValue(value)); }

    Q_PROPERTY(uint BSSExpireCount READ bSSExpireCount WRITE setBSSExpireCount)
    inline uint bSSExpireCount() const
    { return qvariant_cast< uint >(property("BSSExpireCount")); }
    inline void setBSSExpireCount(uint value)
    { setProperty("BSSExpireCount", QVariant::fromValue(value)); }

    Q_PROPERTY(QList<QDBusObjectPath> BSSs READ bSSs)
    inline QList<QDBusObjectPath> bSSs() const
    { return qvariant_cast< QList<QDBusObjectPath> >(property("BSSs")); }

    Q_PROPERTY(QStringList Blobs READ blobs)
    inline QStringList blobs() const
    { return qvariant_cast< QStringList >(property("Blobs")); }

    Q_PROPERTY(QString BridgeIfname READ bridgeIfname)
    inline QString bridgeIfname() const
    { return qvariant_cast< QString >(property("BridgeIfname")); }

    Q_PROPERTY(QVariantMap Capabilities READ capabilities)
    inline QVariantMap capabilities() const
    { return qvariant_cast< QVariantMap >(property("Capabilities")); }

    Q_PROPERTY(QString Country READ country WRITE setCountry)
    inline QString country() const
    { return qvariant_cast< QString >(property("Country")); }
    inline void setCountry(const QString &value)
    { setProperty("Country", QVariant::fromValue(value)); }

    Q_PROPERTY(QString CurrentAuthMode READ currentAuthMode)
    inline QString currentAuthMode() const
    { return qvariant_cast< QString >(property("CurrentAuthMode")); }

    Q_PROPERTY(QDBusObjectPath CurrentBSS READ currentBSS)
    inline QDBusObjectPath currentBSS() const
    { return qvariant_cast< QDBusObjectPath >(property("CurrentBSS")); }

    Q_PROPERTY(QDBusObjectPath CurrentNetwork READ currentNetwork)
    inline QDBusObjectPath currentNetwork() const
    { return qvariant_cast< QDBusObjectPath >(property("CurrentNetwork")); }

    Q_PROPERTY(int DisconnectReason READ disconnectReason)
    inline int disconnectReason() const
    { return qvariant_cast< int >(property("DisconnectReason")); }

    Q_PROPERTY(QString Driver READ driver)
    inline QString driver() const
    { return qvariant_cast< QString >(property("Driver")); }

    Q_PROPERTY(bool FastReauth READ fastReauth WRITE setFastReauth)
    inline bool fastReauth() const
    { return qvariant_cast< bool >(property("FastReauth")); }
    inline void setFastReauth(bool value)
    { setProperty("FastReauth", QVariant::fromValue(value)); }

    Q_PROPERTY(QString Ifname READ ifname)
    inline QString ifname() const
    { return qvariant_cast< QString >(property("Ifname")); }

    Q_PROPERTY(QList<QDBusObjectPath> Networks READ networks)
    inline QList<QDBusObjectPath> networks() const
    { return qvariant_cast< QList<QDBusObjectPath> >(property("Networks")); }

    Q_PROPERTY(QString PKCS11EnginePath READ pKCS11EnginePath)
    inline QString pKCS11EnginePath() const
    { return qvariant_cast< QString >(property("PKCS11EnginePath")); }

    Q_PROPERTY(QString PKCS11ModulePath READ pKCS11ModulePath)
    inline QString pKCS11ModulePath() const
    { return qvariant_cast< QString >(property("PKCS11ModulePath")); }

    Q_PROPERTY(int ScanInterval READ scanInterval WRITE setScanInterval)
    inline int scanInterval() const
    { return qvariant_cast< int >(property("ScanInterval")); }
    inline void setScanInterval(int value)
    { setProperty("ScanInterval", QVariant::fromValue(value)); }

    Q_PROPERTY(bool Scanning READ scanning)
    inline bool scanning() const
    { return qvariant_cast< bool >(property("Scanning")); }

    Q_PROPERTY(QString State READ state)
    inline QString state() const
    { return qvariant_cast< QString >(property("State")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> AddBlob(const QString &name, const QByteArray &data)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name) << QVariant::fromValue(data);
        return asyncCallWithArgumentList(QStringLiteral("AddBlob"), argumentList);
    }

    inline QDBusPendingReply<QDBusObjectPath> AddNetwork(const QVariantMap &args)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(args);
        return asyncCallWithArgumentList(QStringLiteral("AddNetwork"), argumentList);
    }

    inline QDBusPendingReply<> AutoScan(const QString &arg)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(arg);
        return asyncCallWithArgumentList(QStringLiteral("AutoScan"), argumentList);
    }

    inline QDBusPendingReply<> Disconnect()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Disconnect"), argumentList);
    }

    inline QDBusPendingReply<> EAPLogoff()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("EAPLogoff"), argumentList);
    }

    inline QDBusPendingReply<> EAPLogon()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("EAPLogon"), argumentList);
    }

    inline QDBusPendingReply<> FlushBSS(uint age)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(age);
        return asyncCallWithArgumentList(QStringLiteral("FlushBSS"), argumentList);
    }

    inline QDBusPendingReply<QByteArray> GetBlob(const QString &name)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name);
        return asyncCallWithArgumentList(QStringLiteral("GetBlob"), argumentList);
    }

    inline QDBusPendingReply<> NetworkReply(const QDBusObjectPath &path, const QString &field, const QString &value)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path) << QVariant::fromValue(field) << QVariant::fromValue(value);
        return asyncCallWithArgumentList(QStringLiteral("NetworkReply"), argumentList);
    }

    inline QDBusPendingReply<> Reassociate()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Reassociate"), argumentList);
    }

    inline QDBusPendingReply<> Reattach()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Reattach"), argumentList);
    }

    inline QDBusPendingReply<> Reconnect()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Reconnect"), argumentList);
    }

    inline QDBusPendingReply<> RemoveAllNetworks()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("RemoveAllNetworks"), argumentList);
    }

    inline QDBusPendingReply<> RemoveBlob(const QString &name)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(name);
        return asyncCallWithArgumentList(QStringLiteral("RemoveBlob"), argumentList);
    }

    inline QDBusPendingReply<> RemoveNetwork(const QDBusObjectPath &path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path);
        return asyncCallWithArgumentList(QStringLiteral("RemoveNetwork"), argumentList);
    }

    inline QDBusPendingReply<> Scan(const QVariantMap &args)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(args);
        return asyncCallWithArgumentList(QStringLiteral("Scan"), argumentList);
    }

    inline QDBusPendingReply<> SelectNetwork(const QDBusObjectPath &path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(path);
        return asyncCallWithArgumentList(QStringLiteral("SelectNetwork"), argumentList);
    }

    inline QDBusPendingReply<> SetPKCS11EngineAndModulePath(const QString &pkcs11_engine_path, const QString &pkcs11_module_path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(pkcs11_engine_path) << QVariant::fromValue(pkcs11_module_path);
        return asyncCallWithArgumentList(QStringLiteral("SetPKCS11EngineAndModulePath"), argumentList);
    }

    inline QDBusPendingReply<QVariantMap> SignalPoll()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("SignalPoll"), argumentList);
    }

    inline QDBusPendingReply<> SubscribeProbeReq()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("SubscribeProbeReq"), argumentList);
    }

    inline QDBusPendingReply<> TDLSDiscover(const QString &peer_address)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(peer_address);
        return asyncCallWithArgumentList(QStringLiteral("TDLSDiscover"), argumentList);
    }

    inline QDBusPendingReply<> TDLSSetup(const QString &peer_address)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(peer_address);
        return asyncCallWithArgumentList(QStringLiteral("TDLSSetup"), argumentList);
    }

    inline QDBusPendingReply<QString> TDLSStatus(const QString &peer_address)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(peer_address);
        return asyncCallWithArgumentList(QStringLiteral("TDLSStatus"), argumentList);
    }

    inline QDBusPendingReply<> TDLSTeardown(const QString &peer_address)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(peer_address);
        return asyncCallWithArgumentList(QStringLiteral("TDLSTeardown"), argumentList);
    }

    inline QDBusPendingReply<> UnsubscribeProbeReq()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("UnsubscribeProbeReq"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void BSSAdded(const QDBusObjectPath &path, const QVariantMap &properties);
    void BSSRemoved(const QDBusObjectPath &path);
    void BlobAdded(const QString &name);
    void BlobRemoved(const QString &name);
    void Certification(const QVariantMap &certification);
    void EAP(const QString &status, const QString &parameter);
    void NetworkAdded(const QDBusObjectPath &path, const QVariantMap &properties);
    void NetworkRemoved(const QDBusObjectPath &path);
    void NetworkSelected(const QDBusObjectPath &path);
    void ProbeRequest(const QVariantMap &args);
    void PropertiesChanged(const QVariantMap &properties);
    void ScanDone(bool success);
    void StaAuthorized(const QString &name);
    void StaDeauthorized(const QString &name);
};

#endif
