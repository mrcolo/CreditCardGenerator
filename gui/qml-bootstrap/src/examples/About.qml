import QtQuick 2.0
import "../variables/fontawesome.js" as FontAwesome
import "../lists"

Item {
    width: parent.width
    height: parent.height


    ThumbnailListView{
        anchors.fill: parent


        model: ListModel {
            ListElement{
                avatar: "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRfBSdHNVPhwjFgQWZi369wUNMSDcQYFUeaveFKOhy5m-r84mwo"
                title:"Created with: "
            }
            ListElement{
                avatar: "https://logo.clearbit.com/qt.io"
                title:"Qt"
                detail: "IDE"
            }
            ListElement{
                avatar: "https://logo.clearbit.com/getbootstrap.com"
                title:"Qml Bootstrap"
                detail: "UI Components"
            }
            ListElement{
                avatar: "https://logo.clearbit.com/marsbank.com"
                title:"Mars Banks Base"
                detail: "Bank Database"
            }
            ListElement{
                avatar: "https://logo.clearbit.com/coffeecup.com"
                title:"Coffee"
            }
            ListElement{
                avatar: "http://www.skillyoga.com/wp-content/uploads/2018/03/YOGA-LOGO.png"
                title:"Patience"
            }
        }
    }
}
