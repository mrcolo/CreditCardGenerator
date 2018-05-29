TARGET = qml-bootstrap
TEMPLATE = app

QT += qml quick widgets printsupport

SOURCES += main.cpp \
           ../../src/card.cpp

RESOURCES += qml.qrc
OTHER_FILES += \
		main.qml \
		src/variables/base.js \
		src/variables/buttons.js \
		src/variables/colors.js \
		src/variables/items.js \
		src/variables/badges.js \
		src/variables/fontawesome.js \
		src/styles/TouchStyle.qml \
		src/buttons/ButtonDefault.qml \        
		src/styles/TouchOutlineStyle.qml \
		src/styles/ListDividerStyle.qml \
		src/lists/List.qml \
		src/lists/DefaultListView.qml \
		src/lists/IconListView.qml \
		src/styles/DefaulListViewStyle.qml \
		src/styles/IconListViewStyle.qml \
		src/examples/ButtonPage.qml \
		src/examples/DefaultListPage.qml \
    src/lists/AvatarListView.qml \
    src/styles/AvatarListViewStyle.qml \
    src/content/TextContent.qml \
    src/styles/ThumbnailListViewStyle.qml \
    src/lists/ThumbnailListView.qml \
    src/examples/ThumbnailListPage.qml \
    src/styles/TouchClearStyle.qml \
    src/bars/Bar.qml \
    src/variables/bars.js \
    src/bars/ButtonBar.qml \
    src/examples/ButtonBarPage.qml \
    src/cards/Card.qml \
    src/styles/CardStyle.qml



# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =
QMAKE_MAC_SDK = macosx10.9
# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    backend.h \
    ../../src/parse.h \
    ../../src/card.h \
    createCards.h

DISTFILES += \
    src/examples/Visa.qml \
    src/examples/AmericanExpress.qml \
    src/examples/MasterCard.qml
