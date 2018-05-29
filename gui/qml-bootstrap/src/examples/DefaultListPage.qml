import QtQuick 2.0
import "../lists"

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
