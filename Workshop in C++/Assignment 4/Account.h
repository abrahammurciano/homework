/*
 * File Name:				Account.h
 * Program Description:		Program for an ATM machine
 * Course Name:				Workshop in C++
 * Assignment Number:		4
 * Author:					Abraham Murciano
 */

#ifndef Account_h
#define Account_h

#include <iostream>
using namespace std;

class Account {

	friend istream& operator>>(istream& in, Account& a);

  private:
	int id;
	int pin;
	float balance;
	static float sumWithdraw;
	static float sumDeposit;

  public:
	Account();
	Account(int id, int pin, float balance);
	Account(const Account& a);

	void setId(int id);
	void setPin(int pin);
	void setBalance(float balance);

	int getId();
	int getPin();
	float getBalance();

	void withdraw(float money);
	void deposit(float money);

	static float getSumWithdraw();
	static float getSumDeposit();
};

float Account::sumWithdraw = 0;
float Account::sumDeposit = 0;

#endif
