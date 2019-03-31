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

Account::Account(int pin, float balance) {
	setId();
	setPin(pin);
	setBalance(balance);
}

Account::Account(const Account& a) {
	this->id = a.id;
	this->pin = a.pin;
	this->balance = a.balance;
}

void Account::setId() {
	static int newId = 1;
	this->id = newId++;
}

void Account::setPin(int pin) {
	if (this->pin < 1000 || this->pin > 9999) {
		if (pin >= 1000 && pin <= 9999) {
			static int newPin = pin;
			this->pin = newPin;
		} else {
			throw "ERROR: code must be 4 digits and cannot start with 0!";
		}
	} else {
		throw "ERROR: cannot change pin code!";
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
		throw "ERROR: cannot withdraw more than 2500 NIS!";
	}
	if (balance - money < -6000) {
		throw "ERROR: cannot have less than -6000 NIS!";
	}
	if (money < 0) {
		throw "ERROR: cannot withdraw negative number!";
	}
	balance -= money;
	sumWithdraw += money;
}

void Account::deposit(float money) {
	if (money > 10000) {
		throw "ERROR: cannot deposit more than 10000 NIS!";
	}
	if (money < 0) {
		throw "ERROR: cannot deposit negative number!";
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
	int pin;
	in >> pin;
	a.setPin(pin);
	return in;
}