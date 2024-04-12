#include "BankAccount.h"
#include<iostream>
using namespace std;
BankAccount::BankAccount(std::string holderName, int accountNumber, float balance) {
    this->holderName = holderName;
    this->accountNumber = accountNumber;
    this->balance = balance;
}

void BankAccount::setHolderName(std::string holderName) {
    this->holderName = holderName;
}

std::string BankAccount::getHolderName() const {
    return this->holderName;
}

void BankAccount::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}

int BankAccount::getAccountNumber() const {
    return this->accountNumber;
}

void BankAccount::setBalance(float balance) {
    this->balance = balance;
}

float BankAccount::getBalance() const {
    return this->balance;
}

void BankAccount::depositMoney(float x) {
    this->balance += x;
}

void BankAccount::withdrawMoney(float x) {
    if (this->balance < x) {
        cout<<"Insufficient funds";
    }
    else {
        cout <<"Withdrawing "<< x<<" euros.";
        this->balance -= x;
    }
}

std::ostream& operator<<(std::ostream& os, const BankAccount& bankAccount) {
    os << "Holder Name: " << bankAccount.getHolderName() << "\n";
    os << "Account Number: " << bankAccount.getAccountNumber() << "\n";
    os << "Balance: " << bankAccount.getBalance() << "\n";
    return os;
}