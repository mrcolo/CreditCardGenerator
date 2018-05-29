//
// Created by Francesco Colonnese on 5/23/18.
//

#include "card.h"
#include <iostream>
#include <string>
#include <sstream>
#include <random>

using namespace std;

card::card(string bin, string company, string debitcredit, string cardtype, string country, string phone){
    stringstream ss;

    ss<<bin;
    ss>>BIN;

    COMPANY = company;
    DEBITCREDIT = debitcredit;
    CARDTYPE = cardtype;
    COUNTRY = country;
    PHONE = phone;
}

card::card(const string &card_number){
    CARDNUMBER = card_number;
}

card::~card(){

}

card::card(const card& other){
    copy(other);
}

void card::copy(const card& other)
{
    BIN = other.BIN;
    COMPANY = other.COMPANY;
    DEBITCREDIT = other.DEBITCREDIT;
    CARDTYPE = other.CARDTYPE;
    COUNTRY = other.COUNTRY;
    PHONE = other.PHONE;
}
card& card::operator=(const card& other){
    if(this != &other)
        copy(other);

    return *this;
}

void card::generateNumber(){
    srand(time(nullptr));
    string cardNum(to_string(BIN));
    int sum = 0, temp = 0;

    while(cardNum.length() < 15){
        int iNum = (rand() % 10);
        char cNum = static_cast<char>('0' + iNum);
        cardNum.push_back(cNum);
    }
    for(size_t i = 0; i < cardNum.length(); i++){
        if(i%2 == 0){
            temp = (cardNum[i] - '0') * 2;
            if(temp > 9)
                temp -= 9;
            sum += temp;
        }else{
            temp = (cardNum[i] - '0');
            sum += temp;
        }
    }
    int iCheck = (sum*9)%10;
    char cCheck = static_cast<char>('0' + iCheck);
    cardNum.push_back(cCheck);
    CARDNUMBER = cardNum;
}

bool card::isValid(){
    if(CARDNUMBER.length() != 16){
        return false;
    }else{
        int sum = 0, temp = 0;

        for(size_t i = 0; i < CARDNUMBER.length(); i++){
            if(i%2 == 0){
                temp = (CARDNUMBER[i] - '0') * 2;
                if(temp > 9)
                    temp -= 9;
                sum += temp;
            }else{
                temp = (CARDNUMBER[i] - '0');
                sum += temp;
            }
        }
        return (sum % 10 == 0);
    }
}

int card::getBin(){
    return BIN;
}
string card::getCompany(){
    return COMPANY;
}
string card::getDebitCredit(){
    return DEBITCREDIT;
}
string card::getCardType(){
    return CARDTYPE;
}
string card::getCountry(){
    return COUNTRY;
}
string card::getPhone(){
    return PHONE;
}

