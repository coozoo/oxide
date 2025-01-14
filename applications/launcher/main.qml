import QtQuick 2.10
import QtQuick.Window 2.3
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.0
import "widgets"

ApplicationWindow {
    id: window
    objectName: "window"
    visible: true
    width: screenGeometry.width
    height: screenGeometry.height
    title: qsTr("Oxide")
    property int itemPadding: 10
    FontLoader { id: iconFont; source: "/font/icomoon.ttf" }
    Component.onCompleted:{
        stateController.state = "loaded"
        controller.startup();
        appsView.model = controller.getApps();
    }
    Connections {
        target: controller
        onReload: appsView.model = controller.getApps()
    }
    header: Rectangle {
        enabled: stateController.state === "loaded"
        color: "black"
        height: menu.height
        Label {
            objectName: "clock"
            color: "white"
            anchors.centerIn: parent
        }
        RowLayout {
            id: menu
            width: parent.width
            CustomMenu {
                BetterMenu {
                    id: optionsMenu
                    title: "";
                    font: iconFont.name
                    width: 310
                    Action { text: qsTr(" Reload"); onTriggered: appsView.model = controller.getApps() }
                    Action {
                        text: qsTr(" Import Apps");
                        onTriggered:{
                            controller.importDraftApps();
                            appsView.model = controller.getApps();
                        }
                    }
                    Action { text: qsTr(" Options"); onTriggered: stateController.state = "settings" }
                }
            }
            Label { Layout.fillWidth: true }
            Label { Layout.fillWidth: true }
            StatusIcon {
                id: wifiState
                objectName: "wifiState"
                property string state: "unknown"
                property int link: 0
                property int level: 0
                property bool connected: false
                source: {
                    var icon;
                    if(state === "unknown"){
                        icon = "unknown";
                    }else if(state === "down"){
                        icon = "down";
                    }else if(!connected){
                        icon = "disconnected";
                    }else if(link < 20){
                        icon = "0_bar";
                    }else if(link < 40){
                        icon = "1_bar";
                    }else if(link < 60){
                        icon = "2_bar";
                    }else if(link < 80){
                        icon = "3_bar";
                    }else{
                        icon = "4_bar";
                    }
                    return "qrc:/img/wifi/" + icon + ".png";
                }
                text: controller.showWifiDb ? level + "dBm" : ""
                MouseArea {
                    anchors.fill: parent
                    onClicked: stateController.state = "wifi"
                }
            }
            StatusIcon {
                id: batteryLevel
                objectName: "batteryLevel"
                property bool alert: false
                property bool warning: false
                property bool charging: false
                property bool connected: false
                property bool present: true
                property int level: 0
                property int temperature: 0
                source: {
                    var icon = "";
                    if(alert || !present){
                        icon = "alert";
                    }else if(warning){
                        icon = "unknown";
                    }else{
                        if(charging || connected){
                            icon = "charging_";
                        }
                        if(level < 25){
                            icon += "20";
                        }else if(level < 35){
                            icon += "30";
                        }else if(level < 55){
                            icon += "50";
                        }else if(level < 65){
                            icon += "60";
                        }else if(level < 85){
                            icon += "80";
                        }else if(level < 95){
                            icon += "90";
                        }else{
                            icon += 100;
                        }
                    }
                    return "qrc:/img/battery/" + icon + ".png";
                }
                text: (controller.showBatteryPercent ? level + "% " : "") + (controller.showBatteryTemperature ? temperature + "C" : "")
            }
            CustomMenu {
                BetterMenu {
                    id: powerMenu
                    title: "";
                    font: iconFont.name
                    width: 260
                    Action { text: qsTr(" Suspend"); onTriggered: stateController.state = "suspended" }
                    Action { text: qsTr(" Shutdown"); onTriggered: controller.powerOff() }
                }
            }
        }
    }
    background: Rectangle { color: "white" }
    contentData: [
        Rectangle {
            anchors.fill: parent
            color: "white"
        },
        GridView {
            id: appsView
            enabled: stateController.state === "loaded"
            objectName: "appsView"
            anchors.fill: parent
            clip: true
            snapMode: ListView.SnapOneItem
            maximumFlickVelocity: 0
            boundsBehavior: Flickable.StopAtBounds
            cellWidth: parent.width / controller.columns
            cellHeight: cellWidth + controller.fontSize
            model: apps
            ScrollBar.vertical: ScrollBar {
                id: scrollbar
                snapMode: ScrollBar.SnapAlways
                policy: ScrollBar.AlwaysOn
                contentItem: Rectangle {
                    color: "white"
                    implicitWidth: 6
                    implicitHeight: 100
                    radius: width / 2
                }
                background: Rectangle {
                    color: "black"
                    implicitWidth: 6
                    implicitHeight: 100
                    radius: width / 2
                }
            }
            delegate: Item {
                id: root
                enabled: appsView.enabled
                width: appsView.cellWidth
                height: appsView.cellHeight
                state: "released"
                states: [
                    State { name: "released" },
                    State { name: "pressed" }
                ]
                Image {
                    id: image
                    fillMode: Image.PreserveAspectFit
                    y: window.itemPadding
                    width: parent.width - window.itemPadding * 2
                    height: parent.width - window.itemPadding * 2 - controller.fontSize
                    source: model.modelData.imgFile
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    id: name
                    text: (model.modelData.running ? "* " : "") + model.modelData.displayName
                    font.family: "Noto Serif"
                    font.italic: true
                    font.bold: model.modelData.running
                    font.pixelSize: controller.fontSize
                    width: parent.width - window.itemPadding * 2
                    anchors.top: image.bottom
                    anchors.horizontalCenter: image.horizontalCenter
                    horizontalAlignment: Text.AlignHCenter
                    clip: true
                }
                MouseArea {
                    anchors.fill: root
                    enabled: root.enabled
                    onPressed: root.state = "pressed"
                    onReleased: root.state = "released"
                    onCanceled: root.state = "released"
                    onClicked: {
                        root.state = "released"
                        model.modelData.execute();
                    }
                    onPressAndHold: {
                        itemInfo.model = model.modelData;
                        stateController.state = "itemInfo"
                    }
                }
                transitions: [
                    Transition {
                        from: "pressed"; to: "released"
                        ParallelAnimation {
                            PropertyAction { target: image; property: "width"; value: root.width - window.itemPadding * 2 }
                            PropertyAction { target: image; property: "height"; value: root.width - window.itemPadding * 2 - controller.fontSize }
                        }
                    },
                    Transition {
                        from: "released"; to: "pressed"
                        ParallelAnimation {
                            PropertyAction { target: image; property: "width"; value: image.width - 10}
                            PropertyAction { target: image; property: "height"; value: image.height - 10 }
                        }
                    }

                ]
            }
        },
        Popup {
            id: itemInfo
            visible: false
            x: (parent.width / 2) - (width / 2)
            y: (parent.height / 2) - (height / 2)
            closePolicy: Popup.CloseOnPressOutside
            onClosed: stateController.state = "loaded"
            property var model;
            property int textPadding: 10
            function getModel(){
                return itemInfo.model || {
                    imgFile: "",
                    name: "(Unknown)",
                    desc: "",
                    running: false
                }
            }
            width: window.width > (itemImage.width + itemContent.width + (itemInfo.textPadding * 2))
                   ? (itemImage.width + itemContent.width + (itemInfo.textPadding * 2) + itemCloseButton.width)
                   : window.width - 10
            height: itemContent.height + itemAutoStartButton.height
            contentItem: Item {
                anchors.fill: parent
                Item {
                    id: itemImage
                    width: itemContent.height
                    height: itemContent.height
                    Image {
                        fillMode: Image.PreserveAspectFit
                        source: itemInfo.model ? itemInfo.model.imgFile : ""
                        anchors.centerIn: parent
                        width: parent.with - itemInfo.textPadding
                        height: parent.height - itemInfo.textPadding
                    }
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                }
                ColumnLayout {
                    id: itemContent
                    anchors.left: itemImage.right
                    Label {
                        text: (itemInfo.model ? itemInfo.model.displayName : "")
                        topPadding: 0
                        leftPadding: itemInfo.textPadding
                        rightPadding: itemInfo.textPadding
                        bottomPadding: 0
                    }
                    Label {
                        text: (itemInfo.model ? itemInfo.model.desc : "")
                        topPadding: 0
                        leftPadding: itemInfo.textPadding
                        rightPadding: itemInfo.textPadding
                        bottomPadding: 0
                    }
                }
                Label {
                    id: itemAutoStartButton
                    visible: !!itemInfo.model
                    text: !!itemInfo.model && controller.autoStartApplication !== itemInfo.model.name
                          ? "Start this application on boot"
                          : "Don't start this application on boot"
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    padding: 5
                    background: Rectangle {
                        border.color: "black"
                        border.width: 1
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if(!itemInfo.model){
                                return
                            }
                            var name = itemInfo.model.name
                            controller.autoStartApplication = controller.autoStartApplication !== name ? name : "";

                        }
                    }
                }
                Label {
                    id: itemCloseButton
                    visible: !!(itemInfo.model && itemInfo.model.running)
                    text: "Kill"
                    padding: 5
                    anchors.top: parent.top
                    anchors.right: parent.right
                    background: Rectangle {
                        border.color: "black"
                        border.width: 1
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if(itemInfo.model){
                                itemInfo.model.stop();
                                appsView.model = controller.getApps();
                            }
                        }
                    }
                }
            }
        },
        SettingsPopup {
            id: settings
            onClosed: stateController.state = "loaded"
            visible: false
        },
        WifiMenu {
            id: wifi
            onClosed: stateController.state = "loaded"
            visible: false
            model: controller.networks
        }

    ]
    Timer {
        id: sleepTimer
        repeat: false
        interval: 1100
        onTriggered: {
            if(stateController.state == "suspended"){
                controller.suspend();
                stateController.state = "resumed";
            }else{
                stateController.state = stateController.previousState
            }
        }
    }
    StateGroup {
        id: stateController
        property string previousState;
        objectName: "stateController"
        state: "loading"
        states: [
            State { name: "loaded" },
            State { name: "settings" },
            State { name: "itemInfo" },
            State { name: "loading" },
            State { name: "suspended" },
            State { name: "resumed" }
        ]
        transitions: [
            Transition {
                from: "loaded"; to: "suspended"
                SequentialAnimation {
                    PropertyAction { target: stateController; property: "previousState"; value: "loaded" }
                    ScriptAction { script: sleepTimer.start() }
                }
            },
            Transition {
                from: "settings"; to: "suspended"
                SequentialAnimation {
                    PropertyAction { target: stateController; property: "previousState"; value: "settings" }
                    ScriptAction { script: sleepTimer.start() }
                }
            },
            Transition {
                from: "itemInfo"; to: "suspended"
                SequentialAnimation {
                    PropertyAction { target: stateController; property: "previousState"; value: "itemInfo" }
                    ScriptAction { script: sleepTimer.start() }
                }
            },
            Transition {
                from: "suspended"; to: "resumed"
                SequentialAnimation {
                    ScriptAction { script: sleepTimer.start() }
                }
            },
            Transition {
                from: "*"; to: "settings"
                SequentialAnimation {
                    ScriptAction { script: stateController.previousState = "settings" }
                    PropertyAction { target: settings; property: "visible"; value: true }
                    PropertyAction { target: wifi; property: "visible"; value: false }
                    PropertyAction { target: menu; property: "focus"; value: false }
                }
            },
            Transition {
                from: "settings"; to: "loaded"
                SequentialAnimation {
                    PropertyAction { target: settings; property: "visible"; value: false }
                    PropertyAction { target: appsView; property: "focus"; value: true }
                }
            },
            Transition {
                from: "*"; to: "wifi"
                ParallelAnimation {
                    ScriptAction { script: stateController.previousState = "wifi" }
                    PropertyAction { target: wifi; property: "visible"; value: true }
                    PropertyAction { target: settings; property: "visible"; value: false }
                    PropertyAction { target: menu; property: "focus"; value: false }
                }
            },
            Transition {
                from: "wifi"; to: "loaded"
                ParallelAnimation {
                    PropertyAction { target: wifi; property: "visible"; value: false }
                    PropertyAction { target: appsView; property: "focus"; value: true }
                }
            },
            Transition {
                from: "loaded"; to: "itemInfo"
                SequentialAnimation {
                    PropertyAction { target: itemInfo; property: "visible"; value: true }
                    PropertyAction { target: menu; property: "focus"; value: false }
                }
            },
            Transition {
                from: "itemInfo"; to: "loaded"
                SequentialAnimation {
                    PropertyAction { target: itemInfo; property: "visible"; value: false }
                    PropertyAction { target: appsView; property: "focus"; value: true }
                }
            }
        ]
    }
}
