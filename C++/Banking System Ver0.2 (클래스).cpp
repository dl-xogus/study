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
		cout << "����ID: " << ID << endl;
		cout << "�� ��: " << Name << endl;
		cout << "�� ��: " << Money << endl;
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
	cout << "========�� ��=======" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccount()
{
	int id;
	char name[20];
	int money;

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> money;
	cout << endl;

	accArr[accNum++] = new Account(id, name, money);
}

void DeposiMoney()
{
	int id;
	int money;

	cout << "[�� ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;
	cout << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�" << endl << endl;
}

void WithdrawMoney()
{
	int id;
	int money;

	cout << "[�� ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> money;
	cout << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�" << endl << endl;
}

void ShowAllAccount()
{
	cout << "[��������]" << endl;
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
		cout << "�� ��: ";
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
			cout << "�߸��� �����Դϴ�." << endl << endl;
		}
	}
}