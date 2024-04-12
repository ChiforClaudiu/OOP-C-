#pragma once

#include <iostream>
#include <string>

class BankAccount {
private:
    std::string holderName;
    int accountNumber;
    float balance;
public:
    BankAccount(std::string holderName, int accountNumber, float balance);
    void setHolderName(std::string holderName);
    std::string getHolderName() const;
    void setAccountNumber(int accountNumber);
    int getAccountNumber() const;
    void setBalance(float balance);
    float getBalance() const;
    void depositMoney(float x);
    void withdrawMoney(float x);
    friend std::ostream& operator<<(std::ostream& os, const BankAccount& bankAccount);
};