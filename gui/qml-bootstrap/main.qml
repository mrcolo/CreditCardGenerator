import QtQuick 2.3
import QtQuick.Controls 1.2
import "src/lists"
import "src/bars"
import "src/buttons"
import "src/variables/fontawesome.js" as FontAwesome

ApplicationWindow {
    visible: true
    width: 850
    height: 1280
    FontLoader{ source: "qrc:/src/fonts/fontawesome-webfont.ttf"}
    Rectangle {
        anchors.fill: parent
    }
    toolBar: Bar{
        id: titleBar
        leftComponent: Component{
            ButtonDefault{
                class_name: "bar dark clear"
                text: "Back"
                icon: FontAwesome.icons.fa_angle_left
                opacity: stackView.depth > 1 ? 1 : 0
                visible: opacity ? true : false
                Behavior on opacity { NumberAnimation{} }
                onClicked: {
                    stackView.pop()
                    titleBar.title = "CS3A 🔥 Test 2"
                }
            }
        }
        class_name: "header"
        title: "CS3A 🔥 Test 2"
    }

    ListModel {
        id: pageModel
        ListElement {
            text: "Verify a Card 💳"
            page: "src/examples/ButtonPage.qml"
        }
        ListElement {
            text: "Create Cards - Visa 🔵 "
            page: "src/examples/Visa.qml"
        }
        ListElement {
            text: "Create Cards - MasterCard 🔴 "
            page: "src/examples/MasterCard.qml"
        }
        ListElement {
            text: "Create Cards - American Express ⚫ "
            page: "src/examples/AmericanExpress.qml"
        }
        ListElement {
            text: "About ❓ "
            page: "src/examples/About.qml"
        }
    }
    StackView {
        id: stackView
        anchors.fill: parent
        focus: true
        Keys.onReleased: if (event.key === Qt.Key_Back && stackView.depth > 1) {
                             stackView.pop();
                             event.accepted = true;
                         }

        initialItem: Item {
            width: parent.width
            height: parent.height
            DefaultListView{
                model: pageModel
                anchors.fill: parent
                onItemClicked: {
                    stackView.push(Qt.resolvedUrl(item.page))
                    titleBar.title = item.text
                }
            }
        }
    }

    statusBar: Bar{
        class_name: "footer calm"
        title: "Made with ❤️ by Arman and Francesco"
    }
}
