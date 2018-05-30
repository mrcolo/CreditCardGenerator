#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QMessageBox>
#include "../../src/parse.h"
#include "../../src/card.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class BackEnd : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString number READ number WRITE verify NOTIFY userNameChanged)


public:
    parse myParser;

    BackEnd(QObject *parent = nullptr)
    {
        myParser.parseAll();
    }
     ~BackEnd(){

     }
    //verify a card
    Q_INVOKABLE void verify(QString text){

        QMessageBox msgBox;
        string cardToString = text.toUtf8().constData();
        string result;
        card temp(cardToString);

        if(cardToString.length() == 16 && temp.isValid()){
            result+=string("Card is Valid!\n");
            if(cardToString[0] == '4'){
                result+=string("It's a VISA.\n");
                for(int i = 0; i < myParser.myVISA.size();i++)
                    if(stoi(cardToString.substr(0,6)) == myParser.myVISA[i].getBin()){

                        result += string("Company:")+ myParser.myVISA[i].getCompany() +
                                 "\nCard: "+ myParser.myVISA[i].getCardType() +
                                 "\nType: "+ myParser.myVISA[i].getDebitCredit() +
                                 "\nCountry: "+ myParser.myVISA[i].getCountry() +
                                 "\nPhone: "+ myParser.myVISA[i].getPhone();
                    }
            }

            if(cardToString[0] == '3'){
                result+=string("It's an AMERICAN EXPRESS.\n");
                for(int i = 0; i < myParser.myAMEX.size();i++)
                    if(stoi(cardToString.substr(0,6)) == myParser.myAMEX[i].getBin())
                        result += string("Company: ")+ myParser.myAMEX[i].getCompany() +
                                 "\nCard: "+ myParser.myAMEX[i].getCardType() +
                                 "\nType: "+ myParser.myAMEX[i].getDebitCredit() +
                                 "\nCountry: "+ myParser.myAMEX[i].getCountry() +
                                 "\nPhone: "+ myParser.myAMEX[i].getPhone();
            }
            if(cardToString[0] == '5'){
                result+=string("It's a MASTERCARD.\n");
                for(int i = 0; i < myParser.myMS.size();i++)
                    if(stoi(cardToString.substr(0,6)) == myParser.myMS[i].getBin())
                        result += string("Company: ")+ myParser.myMS[i].getCompany() +
                                 "\n"+"Card: " + myParser.myMS[i].getCardType() +
                                 "\n"+"Type: " + myParser.myMS[i].getDebitCredit() +
                                 "\n"+"Country: " + myParser.myMS[i].getCountry() +
                                 "\n"+"Phone: "+ myParser.myMS[i].getPhone();
            }



            QString qstr = QString::fromStdString(result);
            msgBox.setText(qstr);
            msgBox.exec();
        }
        else{
              msgBox.setText("Card Not Valid");
              msgBox.exec();
        }
    }
};

#endif // BACKEND_H
