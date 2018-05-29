import QtQuick 2.3
import QtQuick.Controls 1.2
import "src/lists"
import "src/bars"
import "src/buttons"
import "src/variables/fontawesome.js" as FontAwesome

ApplicationWindow {
    visible: true
    width: 800
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
                    titleBar.title = "CS3A | Test 2"
                }
            }
        }

        class_name: "header"
        title: "CS3A 🔥 Test 2"
    }

    ListModel {
        id: pageModel
        ListElement {
            text: "Verify a Credit Card"
            page: "src/examples/ButtonPage.qml"
        }
        ListElement {
            text: "Create Credit Card"
            page: "src/examples/DefaultListPage.qml"
        }
    }

    Item {
        width: parent.width
        height: parent.height
        DefaultListView{
            id: listView
            hasDivider: true
            anchors.fill: parent
            onItemClicked: {
                listView.model.get(index).text = "Item clicked";
            }

            model: myModel
            delegate: Rectangle {
                    height: 25
                    width: 100
                    Text { text: "modelData" }
                }
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
