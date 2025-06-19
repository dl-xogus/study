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

	accArr[accNum].ID = id;
	accArr[accNum].Money = money;
	strcpy(accArr[accNum].Name, name);
	accNum++;
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
		if(id != accArr[i].ID)
			cout << "��ȿ���� ���� ID�Դϴ�" << endl << endl;

		accArr[i].Money += money;
		cout << "�ԱݿϷ�" << endl << endl;
	}
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
		if (id != accArr[i].ID)
			cout << "��ȿ���� ���� ID�Դϴ�" << endl << endl;

		if (accArr[i].Money < money)
		{
			cout << "�ܾ׺���" << endl << endl;
			return;
		}
		accArr[i].Money -= money;
		cout << "��ݿϷ�" << endl << endl;
	}
}

void ShowAllAccount()
{
	cout << "[��������]" << endl;
	for (int i = 0; i < accNum; i++)
	{
		cout << "����ID: " << accArr[i].ID << endl;
		cout << "�� ��: " << accArr[i].Name << endl;
		cout << "�� ��: " << accArr[i].Money << endl << endl;
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
			return 0;
		default:
			cout << "�߸��� �����Դϴ�." << endl << endl;
		}
	}
}