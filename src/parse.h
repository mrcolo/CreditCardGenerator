//
// Created by Francesco Colonnese on 5/28/18.
//

#ifndef PARSER_PARSE_H
#define PARSER_PARSE_H
#include "card.h"
#include <fstream>
#include <iostream>
#include <vector>


class parse {
public:
    parse(bool shouldParse = false){
        if(shouldParse){
            isParsed = true;
            parseVISA(myVISA);
            parseAMERICANEXPRESS(myAMEX);
            parseMASTERCARD(myMS);
        }
    }

    ~parse(){
    }
    bool isParsed = false;
    vector<card> myVISA;
    vector<card> myMS;
    vector<card> myAMEX;

    void parseVISA(vector<card>& myData){

        ofstream out;
        out.open("../../../../../data/parsed/dbvisa.txt");

        std::ifstream is ("../../../../../data/notparsed/visa.txt", std::ifstream::binary);
        if (is) {

            // get length of file:
            is.seekg(0, is.end);
            int length = is.tellg();
            is.seekg(0, is.beg);

            char *buffer = new char[length];

            std::cout << "Reading " << length << " characters... ";

            is.read(buffer, length);

            if (is)
                std::cout << "all characters read successfully."<<endl;
            else
                std::cout << "error: only " << is.gcount() << " could be read"<<endl;

            is.close();

            string PREVIOUS_BIN;

            for(int i = 0; i < length; i++){
                string BIN,COMPANY,CARD,TYPE,COUNTRY,PHONE;
                if(*(buffer + i) == '\u0006') {
                    int space_basic = *(buffer + i);
                    int space_begin = *(buffer + i + 1);
                    int space_cardtype1 = *(buffer + i + 2);
                    int space_cardtype2 = *(buffer + i + 3);
                    int space_country = *(buffer + i + 4);
                    int space_phone =  *(buffer + i + 5);
                    int space_company = *(buffer + i + 12);

                    for(int j = i; j < (i + space_basic) ; j++ )
                        if(isprint(*(buffer + j + space_basic)) &&  *(buffer + i + space_basic) == '4')
                            BIN+=*(buffer + j + space_basic);

                    for(int j = i + 2*space_basic + space_begin; j < (i + 2*space_basic + space_begin + space_company) ; j++ )
                        if(isprint(*(buffer + j)))
                            COMPANY+=*(buffer + j);

                    for(int j = i + 2*space_basic + space_begin + space_company; j < (i + 2*space_basic + space_begin + space_company + space_cardtype1) ; j++ )
                        if(isprint(*(buffer + j)))
                            CARD+=*(buffer + j);

                    for(int j = i + 2*space_basic + space_begin + space_company + space_cardtype1; j < (i + 2*space_basic + space_begin + space_company + space_cardtype1 + space_cardtype2) ; j++ )
                        if(isprint(*(buffer + j)))
                            TYPE+=*(buffer + j);

                    for(int j = i + 2*space_basic + space_begin + space_company + space_cardtype1 + space_cardtype2; j < (i + 2*space_basic + space_begin + space_company + space_cardtype1 + space_cardtype2 + space_country) ; j++ )
                        if(isprint(*(buffer + j)))
                            COUNTRY+=*(buffer + j);

                    for(int j = i + 2*space_basic + space_begin + space_company + space_cardtype1 + space_cardtype2 + space_country; j < (i + 2*space_basic + space_begin + space_company + space_cardtype1 + space_cardtype2 + space_country + space_phone) ; j++ )
                        if(isprint(*(buffer + j)))
                            PHONE+=*(buffer + j);

                    card temp(BIN,COMPANY,CARD,TYPE,COUNTRY,PHONE);

                    if(temp.getBin()/100000 == 4 && PREVIOUS_BIN != BIN)
                        myData.push_back(temp);

                }

            }

            delete[] buffer;
        }
        else{
            cout<<"stream not working!"<<endl;
        }

        for(int i = 0; i < myData.size(); i++){
            out<<"BIN: "<<myData[i].getBin()<<endl;
            out<<"COMPANY: "<<myData[i].getCompany()<<endl;
            out<<"CARD: "<<myData[i].getDebitCredit()<<endl;
            out<<"TYPE: "<<myData[i].getCardType()<<endl;
            out<<"COUNTRY: "<<myData[i].getCountry()<<endl;
            out<<"PHONE: "<<myData[i].getPhone()<<endl;
            out<<endl<<endl;
        }
        cout<<"VISA DATABASE HAS BEEN PARSED"<<endl;
        out.close();
    }
    void parseMASTERCARD(vector<card>& myData){

        ofstream out;
        out.open("../../../../../data/parsed/dbmc.txt");

        std::ifstream is ("../../../../../data/notparsed/mc.txt", std::ifstream::binary);

        if (is) {

            // get length of file:
            is.seekg(0, is.end);
            int length = is.tellg();
            is.seekg(0, is.beg);

            char *buffer = new char[length];

            std::cout << "Reading " << length << " characters... ";

            is.read(buffer, length);

            if (is)
                std::cout << "all characters read successfully."<<endl;
            else
                std::cout << "error: only " << is.gcount() << " could be read"<<endl;

            is.close();

            string PREVIOUS_BIN;

            for(int i = 0; i < length/8; i++){
                string BIN,COMPANY,CARD,TYPE,COUNTRY,PHONE;

                if(*(buffer + i) == '\u0006') {
                    int space_bin = 6;
                    int space_basic = 4;
                    int space_begin = *(buffer + i + 1);
                    int space_country = *(buffer + i + 2);
                    int space_phone =  *(buffer + i + 3);
                    int space_company = *(buffer + i + 10);

                    for(int j = i; j < (i + space_basic + space_bin) ; j++ )
                        if(isprint(*(buffer + j + space_basic)) &&  *(buffer + i + space_basic) == '5')
                            BIN+=*(buffer + j + space_basic);

                    for(int j = i + space_basic + space_bin + space_begin; j < (i + space_basic + space_bin + space_begin + space_company) ; j++ )
                        if(isprint(*(buffer + j)))
                            COMPANY+=*(buffer + j);

                    for(int j = i + space_basic + space_bin + space_begin + space_company; j < (i + space_basic + space_bin + space_begin + space_company + space_country) ; j++ )
                        if(isprint(*(buffer + j)))
                            COUNTRY+=*(buffer + j);

                    for(int j = i + space_basic + space_bin + space_begin + space_company + space_country; j < (i + space_basic + space_bin + space_begin + space_company + space_country + space_phone) ; j++ )
                        if(isprint(*(buffer + j)))
                            PHONE+=*(buffer + j);

                    card temp(BIN,COMPANY,CARD,TYPE,COUNTRY,PHONE);

                    if(temp.getBin()/100000 == 5 && PREVIOUS_BIN != BIN)
                        myData.push_back(temp);

                }

            }

            delete[] buffer;
        }
        else{
            cout<<"stream not working!"<<endl;
        }

        for(int i = 0; i < myData.size(); i++){
            out<<"BIN: "<<myData[i].getBin()<<endl;
            out<<"COMPANY: "<<myData[i].getCompany()<<endl;
            out<<"COUNTRY: "<<myData[i].getCountry()<<endl;
            out<<"PHONE: "<<myData[i].getPhone()<<endl;
            out<<endl<<endl;
        }
        cout<<"MASTERCARD DATABASE HAS BEEN PARSED"<<endl;
        out.close();
    }
    void parseAMERICANEXPRESS(vector<card>& myData){

        ofstream out;
        out.open("../../../../../data/parsed/dbamex.txt");
        std::ifstream is ("../../../../../data/notparsed/amex.txt", std::ifstream::binary);

        if (is) {

            // get length of file:
            is.seekg(0, is.end);
            int length = is.tellg();
            is.seekg(0, is.beg);

            char *buffer = new char[length];

            std::cout << "Reading " << length << " characters... ";

            is.read(buffer, length);

            if (is)
                std::cout << "all characters read successfully."<<endl;
            else
                std::cout << "error: only " << is.gcount() << " could be read"<<endl;

            is.close();

            string PREVIOUS_BIN;

            for(int i = 0; i < length; i++){
                string BIN,COMPANY,CARD,TYPE,COUNTRY,PHONE;

                if(*(buffer + i) == '\u0006') {
                    int space_bin = 6;
                    int space_basic = 5;
                    int space_country = *(buffer + i + 1);
                    int card_type1 = *(buffer + i + 2);
                    int card_type2 = *(buffer + i + 3);
                    int space_phone =   *(buffer + i + 4);

                    for(int j = i; j < (i + space_bin) ; j++ )
                        if(isprint(*(buffer + j + space_basic)) &&  *(buffer + i + space_basic) == '3')
                            BIN+=*(buffer + j + space_basic);

                    for(int j = i + space_basic + space_bin; j < (i + space_basic + space_bin + space_country) ; j++ )
                        if(isprint(*(buffer + j)))
                            COUNTRY+=*(buffer + j);

                    for(int j = i + space_basic + space_bin + space_country; j < (i + space_basic + space_bin + space_country + card_type1) ; j++ )
                        if(isprint(*(buffer + j)))
                            CARD+=*(buffer + j);

                    for(int j = i + space_basic + space_bin + space_country + card_type1; j < (i + space_basic + space_bin + space_country + card_type1 + card_type2) ; j++ )
                        if(isprint(*(buffer + j)))
                            TYPE+=*(buffer + j);

                    for(int j = i + space_basic + space_bin + space_country + card_type1 + card_type2; j < (i + space_basic + space_bin + space_country + card_type1 + card_type2 + space_phone) ; j++ )
                        if(isprint(*(buffer + j)))
                            PHONE+=*(buffer + j);

                    card temp(BIN,"American Express",CARD,TYPE,COUNTRY,PHONE);
                    if(temp.getBin()/100000 == 3 && PREVIOUS_BIN != BIN)
                        myData.push_back(temp);

                }

            }

            delete[] buffer;
        }
        else{
            cout<<"stream not working!"<<endl;
        }

        for(int i = 0; i < myData.size(); i++){
            out<<"BIN: "<<myData[i].getBin()<<endl;
            out<<"COMPANY: "<<myData[i].getCompany()<<endl;
            out<<"COUNTRY: "<<myData[i].getCountry()<<endl;
            out<<"CARD: "<<myData[i].getDebitCredit()<<endl;
            out<<"TYPE: "<<myData[i].getCardType()<<endl;
            out<<"PHONE: "<<myData[i].getPhone()<<endl;
            out<<endl<<endl;
        }
        cout<<"AMERICAN EXPRESS DATABASE HAS BEEN PARSED"<<endl;
        out.close();
    }
    void parseAll(){
        isParsed = true;
        parseVISA(myVISA);
        parseAMERICANEXPRESS(myAMEX);
        parseMASTERCARD(myMS);
    }
};


#endif //PARSER_PARSE_H
