#include "BankAccount.h";
using namespace std;

//Design a simple C++ class named BankAccount to represent a basic bank account. The
//class should have attributes for the account holder's name, account number, and balance. Include
//methods for depositingand withdrawing funds, as well as the stream insertion operator to display the account details.
//	a.Implement a parameterized constructor to initialize the account with the account holder's
//	  name, account number, and initial balance.
//	b.Include methods for depositingand withdrawing funds, adjusting the balance accordingly.
//	  Think about how you will handle the case in which the user wants to withdraw more money
//	  than the available amount.
//	c.In the stream insertion operator add the account details : the account holder's name, account
//	  number, and current balance.

int main() {
	BankAccount acc1("Smith", 200012, 6001.00);
	cout << acc1;
	acc1.depositMoney(50000);
	cout << acc1;
	acc1.withdrawMoney(200);
	cout << acc1;
}