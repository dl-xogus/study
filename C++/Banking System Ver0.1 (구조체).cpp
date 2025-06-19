#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

typedef struct account
{
	int ID;
	char Name[20];
	int Money;
} Account;

Account accArr[100];
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

	accArr[accNum].ID = id;
	accArr[accNum].Money = money;
	strcpy(accArr[accNum].Name, name);
	accNum++;
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
		if(id != accArr[i].ID)
			cout << "유효하지 않은 ID입니다" << endl << endl;

		accArr[i].Money += money;
		cout << "입금완료" << endl << endl;
	}
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
		if (id != accArr[i].ID)
			cout << "유효하지 않은 ID입니다" << endl << endl;

		if (accArr[i].Money < money)
		{
			cout << "잔액부족" << endl << endl;
			return;
		}
		accArr[i].Money -= money;
		cout << "출금완료" << endl << endl;
	}
}

void ShowAllAccount()
{
	cout << "[계좌정보]" << endl;
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌ID: " << accArr[i].ID << endl;
		cout << "이 름: " << accArr[i].Name << endl;
		cout << "잔 액: " << accArr[i].Money << endl << endl;
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
			return 0;
		default:
			cout << "잘못된 선택입니다." << endl << endl;
		}
	}
}