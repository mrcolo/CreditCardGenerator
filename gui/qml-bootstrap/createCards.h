#ifndef CREATECARDS_H
#define CREATECARDS_H

#include <QObject>
#include <QString>
#include <QMessageBox>
#include "../../src/parse.h"
#include "../../src/card.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <QStringList>
#include <QFileInfo>
#include <QPrinter>
#include <QtWidgets>

using namespace std;
//first key, sort by company
struct key1
{
    inline bool operator() ( card& card1,  card& card2)
    {

        return (card1.getCompany() < card2.getCompany());
    }
};
//second key, sort by cardtype
struct key2
{
    inline bool operator() ( card& card1,  card& card2)
    {
        return (card1.getCardType() < card2.getCardType());
    }
};

class CreateCards : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString number READ number WRITE verify NOTIFY userNameChanged)

public:
    parse myParser;
    QString result;
    CreateCards(QObject *parent = nullptr)
    {
        myParser.parseAll();
    }
     ~CreateCards(){

    }


   Q_INVOKABLE void sortBy(int choice, int type){
       if(type == 0){

           cout<<"Sorting VISA"<<endl;
           switch(choice){
               case 0:
                   std::sort(myParser.myVISA.begin(), myParser.myVISA.end(), key1());
               break;
               case 1:
                   std::sort(myParser.myVISA.begin(), myParser.myVISA.end(), key2());
               break;
           }
       }

       if(type == 1){
           switch(choice){
               case 0:
                   std::sort(myParser.myMS.begin(),myParser.myMS.end(), key1());
               break;
               case 1:
                   std::sort(myParser.myMS.begin(), myParser.myMS.end(), key2());
               break;
           }
       }

       if(type == 2){
           cout<<"Sorting American Express"<<endl;
           switch(choice){
               case 0:
                   std::sort(myParser.myAMEX.begin(),myParser.myAMEX.end(), key1());
               break;
               case 1:
                   std::sort(myParser.myAMEX.begin(), myParser.myAMEX.end(), key2());
               break;
           }
       }


   }



   Q_INVOKABLE QStringList display(int choice){

        QStringList dataList;

       switch(choice){
        case 0:
           for(int i = 0; i < myParser.myVISA.size(); i++){
               QString temp = QString::fromStdString( string("Card Number: ") + myParser.myVISA[i].generateNumber() + "\n" + string("Company: ") + myParser.myVISA[i].getCompany() + "\n" + string("Country: ") + myParser.myVISA[i].getCountry() + "\n" + string("Card: ") + myParser.myVISA[i].getCardType() + "\n" + string("Type: ") + myParser.myVISA[i].getDebitCredit() + "\n");
               result += (QString("<p>") + temp + QString("</p>"));
               dataList.append(temp);
           }
            break;

         case 1:
            for(int i = 0; i < myParser.myMS.size(); i++){
                QString temp = QString::fromStdString( string("Card Number: ") + myParser.myMS[i].generateNumber() + "\n" + string("Company: ") + myParser.myMS[i].getCompany() + "\n" + string("Country: ") + myParser.myMS[i].getCountry() + "\n");
                result += (QString("<p>") + temp + QString("</p>"));
                dataList.append(temp);
            }
            break;

         case 2:
            for(int i = 0; i < myParser.myAMEX.size(); i++){
                QString temp =  QString::fromStdString(string("Card Number: ") + myParser.myAMEX[i].generateNumber() + "\n" + string("Company: ") + myParser.myAMEX[i].getCompany() + "\n" + string("Type: ") + myParser.myAMEX[i].getCardType() + "\n");
                result += (QString("<p>") + temp + QString("</p>"));
                dataList.append(temp);
            }
            break;

        }

        return dataList;

    }

    Q_INVOKABLE void renderPDF(){
           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
           if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

           QTextDocument doc;
           doc.setHtml(QString("<p>") + result + QString("</p>"));
           doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
           doc.print(&printer);
     }
};

#endif // CREATECARDS_H
