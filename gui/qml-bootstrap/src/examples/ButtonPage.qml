import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import "../buttons"
import "../bars"
import "../variables/fontawesome.js" as FontAwesome
import io.qt.examples.backend 1.0

Item {
    width: parent.width
    height: parent.height
    ColumnLayout {
        spacing: 10
        anchors.fill: parent
        anchors.topMargin: 10

        RowLayout{
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            Layout.preferredWidth: parent.width - 20
            BackEnd {
                    id: backend
                }
            Column {
                spacing: 10
                Layout.alignment: Qt.AlignTop
                TextField {
                        id:cardnumber
                        width: 500;
                        height: 60;
                        placeholderText: qsTr("Credit Card Number")
                    }
                ButtonBar{
                         class_name: "stable"
                         model: [
                                   {
                                       text: 'Verify 💵 💵 💵'
                                   }
                               ]
                               onClick: {
                                   backend.verify(cardnumber.text);
                               }

            }

        }
    }
}
}
