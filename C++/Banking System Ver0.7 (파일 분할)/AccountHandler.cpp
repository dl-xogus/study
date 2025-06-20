#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

void AccountHandler::ShowMenu() const
{
	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount()
{
	int sel;
	cout << "[������������]" << endl;
	cout << "1. ���뿹�ݰ���" << endl;
	cout << "2. �ſ�ŷڰ���" << endl;
	cout << "�� ��: "; cin >> sel;
	cout << endl;

	if (sel == NORMAL)
		MakeNormalAccount();
	else if (sel == CREDIT)
		MakeCreditAccount();
	else
		cout << "�߸��� �����Դϴ�." << endl << endl;
}

void AccountHandler::MakeNormalAccount()
{
	int ID;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> ID;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(ID, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount()
{
	int ID;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID: "; cin >> ID;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(ID, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(ID, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(ID, balance, name, interRate, LEVEL_C);
	}
}

void AccountHandler::DepositMoney()
{
	int ID;
	int money;

	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> ID;
	cout << "�Աݾ�: "; cin >> money;
	cout << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == ID)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void AccountHandler::WithdrawMoney()
{
	int ID;
	int money;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> ID;
	cout << "��ݾ�: "; cin >> money;
	cout << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == ID)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

AccountHandler::AccountHandler() : accNum(0)
{
	for (int i = 0; i < 100; i++)
	{
		accArr[i] = nullptr;
	}
}

void AccountHandler::ShowAllAccInfo() const
{
	cout << "[��������]" << endl;
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete[] accArr[i];
}