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
    //TODO use Luhn to generate number based on BIN.
}

bool card::isValid(){
    if(CARDNUMBER.length() != 16){
        return false;
    }else{
        int sum = 0, temp = 0;
        string luhn_numbers(CARDNUMBER.substr(0,string::npos));

        for(size_t i = 0; i < luhn_numbers.length(); i++){
            if(i%2 == 0 && i != luhn_numbers.length()-1){
                temp = (luhn_numbers[i] - '0') * 2;
                if(temp > 9)
                    temp -= 9;
                sum += temp;
            }else{
                temp = (luhn_numbers[i] - '0');
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

