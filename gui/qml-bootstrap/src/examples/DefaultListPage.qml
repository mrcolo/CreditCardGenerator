import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import "../buttons"
import "../lists"
import "../bars"
import io.qt.examples.createcards 1.0

ListView {
    width: 500; height: 500
    CreateCards {
            id: createcards
    }
    Component {
           id: fruitDelegate
           ButtonDefault {
                 text: modelData
                 height: 50
           }
       }

       ListView {
           anchors.fill: parent
           model: createcards.display()
           delegate: fruitDelegate
       }
}
