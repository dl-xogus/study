#pragma once
#include "Account.h"

class NormalAccount : public Account
{
private:
	int interRate;	// 이자율 %단위

public:
	NormalAccount(int ID, int money, const char* name, int rate) : Account(ID, money, name), interRate(rate) {}

	void Deposit(int money)
	{
		Account::Deposit(money);						// 원금추가
		Account::Deposit(money * (interRate / 100.0));	// 이자추가
	}
};
