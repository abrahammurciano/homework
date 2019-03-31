/*
 * File Name:				Account.cpp
 * Program Description:		Program for an ATM machine
 * Course Name:				Workshop in C++
 * Assignment Number:		4
 * Author:					Abraham Murciano
 */

#include "Account.h"
//#include "iostream"
// using namespace std;

float Account::sumWithdraw = 0;
float Account::sumDeposit = 0;

Account::Account() {
	this->id = 0;
	this->pin = 0;
	this->balance = 0;
}

Account::Account(int id, int pin, float balance) {
	setId(id);
	setPin(pin);
	setBalance(balance);
}

Account::Account(const Account& a) {
	this->id = a.id;
	this->pin = a.pin;
	this->balance = a.balance;
}

void Account::setId(int id) {
	this->id = id;
}

void Account::setPin(int pin) {
	if (this->pin < 1000 || this->pin > 9999) {
		if (pin >= 1000 && pin <= 9999) {
			this->pin = pin;
		} else {
			throw string("ERROR: code must be of 4 digits!");
		}
	} else {
		throw string("ERROR: cannot change pin code!");
	}
}

void Account::setBalance(float balance) {
	this->balance = balance;
}

int Account::getId() {
	return id;
}

int Account::getPin() {
	return pin;
}

float Account::getBalance() {
	return balance;
}

void Account::withdraw(float money) {
	if (money > 2500) {
		throw string("ERROR: cannot withdraw more than 2500 NIS!");
	}
	if (balance - money < -6000) {
		throw string("ERROR: cannot have less than -6000 NIS!");
	}
	if (money < 0) {
		throw string("ERROR: cannot withdraw negative number!");
	}
	balance -= money;
	sumWithdraw += money;
}

void Account::deposit(float money) {
	if (money > 10000) {
		throw string("ERROR: cannot deposit more than 10000 NIS!");
	}
	if (money < 0) {
		throw string("ERROR: cannot deposit negative number!");
	}
	balance += money;
	sumDeposit += money;
}

float Account::getSumWithdraw() {
	return sumWithdraw;
}

float Account::getSumDeposit() {
	return sumDeposit;
}

istream& operator>>(istream& in, Account& a) {
	int id, pin;
	in >> id;
	in >> pin;
	a.setId(id);
	a.setPin(pin);
	return in;
}