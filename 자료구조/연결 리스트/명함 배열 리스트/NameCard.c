#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

// NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
NameCard* MakeNameCard(char* name, char* phone)
{
	NameCard* newCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(newCard->name, name);
	strcpy(newCard->phone, phone);
	return newCard;
}

// NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard* pcard)
{
	printf("[�̸�]: %s \n", pcard->name);
	printf("[��ȣ]: %s \n\n", pcard->phone);
}

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard* pcard, char* name)
{
	return strcmp(pcard->name, name);
}

// ��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard* pcard, char* phone)
{
	strcpy(pcard->phone, phone);
}