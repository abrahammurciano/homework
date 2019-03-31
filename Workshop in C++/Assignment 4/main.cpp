/*
 * File Name:				main.cpp
 * Program Description:		Program for an ATM machine
 * Course Name:				Workshop in C++
 * Assignment Number:		4
 * Author:					Abraham Murciano
 */

#include "Account.h"
#include "Clock.h"
#include <iostream>
using namespace std;

// Function that prints the options available and returns the chosen option
int menu() {
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	// There is a mistake in the question
	// Withdraws should be 5, deposits should be 4
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl << endl;

	try {
		int choice;
		cin >> choice;
		if (choice < 0 || choice > 5) {
			throw string("ERROR: choose an option between 0 and 5");
		}
		return choice;
	} catch (string e) {
		cout << e << endl;
		return menu();
	}
}

// Function which asks for an account number and pin, and returns the account if login was
// successful
Account& login(Account* bank, int size) {

	int id, pin;
	cout << "please enter account number: " << endl;
	cin >> id;
	for (int i = 0; i < size; i++) {
		if (id == bank[i].getId()) {
			cout << "please enter the code:" << endl;
			cin >> pin;
			if (pin == bank[i].getPin()) {
				return bank[i];
			} else {
				throw string("ERROR: wrong code!");
			}
		}
	}
	throw string("ERROR: no such account number!");
}

int main() {

	const int size = 10;
	Account bank[size];
	Clock t(8, 0, 0);

	// Read in 10 bank accounts
	cout << "enter account number and code for 10 accounts:" << endl;
	for (int i = 0; i < 10; i++) {
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++) {
				if (bank[j].getId() == bank[i].getId()) {
					throw string("ERROR: account number must be unique!");
				}
			}
		} catch (string e) {
			cout << t << '\t' << e << endl;
			bank[i] = Account();
			i--;
			continue;
		}
	}

	while (true) {
		try {
			int option = menu();

			if (option == 0) {
				return 0;
			}

			else if (option == 1) {  // Get account balance
				Account& account = login(bank, size);
				t += 20;
				cout << t << '\t' << "account #: " << account.getId() << '\t'
					 << "balance: " << account.getBalance() << endl;
			}

			else if (option == 2) {  // Deposit money
				Account& account = login(bank, size);
				float amount;
				cout << "enter the amount of the check: " << endl;
				cin >> amount;
				account.deposit(amount);
				t += 30;
				cout << t << '\t' << "account #: " << account.getId() << '\t'
					 << "new balance: " << account.getBalance() << endl;
			}

			else if (option == 3) {  // Withdraw money
				Account& account = login(bank, size);
				float amount;
				cout << "enter the amount of money to withdraw: " << endl;
				cin >> amount;
				account.withdraw(amount);
				t += 50;
				cout << t << '\t' << "account #: " << account.getId() << '\t'
					 << "new balance: " << account.getBalance() << endl;
			}

			else if (option == 4) {  // See the sum of all deposits
				t += 60;
				cout << t << '\t' << "sum of all deposits: " << Account::getSumDeposit() << endl;
			}

			else if (option == 5) {  // See the sum of all withdraws
				t += 60;
				cout << t << '\t' << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
			}
		} catch (string e) {
			cout << t << ": " << e << endl;
		}
	}

	return 0;
}

/*
========== Sample Run - start ==========

=========== Sample Run - end ===========
----------------------------------------
*/