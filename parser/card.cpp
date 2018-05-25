//
// Created by Francesco Colonnese on 5/23/18.
//

#include "card.h"
#include <string>
#include <sstream>
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

