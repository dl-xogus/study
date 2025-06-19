#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Account
{
private:
	int ID;
	char* Name;
	int Money;

public:
	Account(int id, char* name, int money) : ID(id), Money(money)
	{
		Name = new char[strlen(name) + 1];
		strcpy(Name, name);
	}
	int GetAccID()
	{
		return ID;
	}
	void Deposit(int money)
	{
		Money += money;
	}
	int Withraw(int money)
	{
		if (Money < money)
			return 0;
		Money -= money;
		return money;
	}
	void ShowAccInfo()
	{
		cout << "계좌ID: " << ID << endl;
		cout << "이 름: " << Name << endl;
		cout << "잔 액: " << Money << endl;
	}
	~Account()
	{
		delete[] Name;
	}
};

Account* accArr[100];
int accNum = 0;

void ShowMenu()
{
	cout << "========메 뉴=======" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount()
{
	int id;
	char name[20];
	int money;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;
	cout << endl;

	accArr[accNum++] = new Account(id, name, money);
}

void DeposiMoney()
{
	int id;
	int money;

	cout << "[입 금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;
	cout << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다" << endl << endl;
}

void WithdrawMoney()
{
	int id;
	int money;

	cout << "[출 금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> money;
	cout << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withraw(money) == 0)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다" << endl << endl;
}

void ShowAllAccount()
{
	cout << "[계좌정보]" << endl;
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

int main()
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선 택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			MakeAccount();
			break;
		case 2:
			DeposiMoney();
			break;
		case 3:
			WithdrawMoney();
			break;
		case 4:
			ShowAllAccount();
			break;
		case 5:
			for (int i = 0; i < accNum; i++)
				delete accArr[i];
			return 0;
		default:
			cout << "잘못된 선택입니다." << endl << endl;
		}
	}
}