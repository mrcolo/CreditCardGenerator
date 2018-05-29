//
// Created by Francesco Colonnese on 5/23/18.
//
#include <string>
#ifndef UNTITLED55_CARD_H
#define UNTITLED55_CARD_H

using namespace std;

class card {
public:
    card(string bin, string company, string debitcredit, string cardtype, string country, string phone);
    explicit card(const string &card_number);
    ~card();
    card(const card& other);
    card& operator=(const card& other);

    string generateNumber();
    int getBin();
    string getCompany();
    string getDebitCredit();
    string getCardType();
    string getCountry();
    string getPhone();
    bool isValid();

private:
    int BIN;
    string COMPANY;
    string DEBITCREDIT;
    string CARDTYPE;
    string COUNTRY;
    string PHONE;
    string CARDNUMBER;
    void copy(const card& other);
};


#endif //UNTITLED55_CARD_H
