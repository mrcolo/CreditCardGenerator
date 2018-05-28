#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QMessageBox>
#include "../../parser/parse.h"
#include <iostream>

using namespace std;

class BackEnd : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString number READ number WRITE verify NOTIFY userNameChanged)

public:
    explicit BackEnd(QObject *parent = nullptr)
    {

    }

    Q_INVOKABLE QString verify(QString text){
        QMessageBox msgBox;

        string cardToString = text.toUtf8().constData();
        if(cardToString.length() == 16){
            if(cardToString[0] == '4')
                msgBox.setText("Visa");
            if(cardToString[0] == '3')
                msgBox.setText("American Express");
            if(cardToString[0] == '5')
                msgBox.setText("Mastercard");
        }
        else{
              msgBox.setText("Card Not Valid");
        }

        if(!text.isEmpty()){
            msgBox.exec();
        }
    }
};

#endif // BACKEND_H
