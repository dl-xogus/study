#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee* WhosNightDuty(List* plist, char* name, int day)
{
	Employee* ret;
	int num = LCount(plist);
	int i;

	LFirst(plist, &ret);

	if (strcmp(ret->name, name) != 0)
	{
		for (i = 0; i < num - 1; i++)
		{
			LNext(plist, &ret);

			if (strcmp(ret->name, name) == 0)
				break;
		}
		if (i >= num - 1)
			return NULL;
	}

	for (i = 0; i < day; i++)
		LNext(plist, &ret);

	return ret;
}

void ShowEmployeeInfo(Employee* emp)
{
	printf("Employee name: %s \n", emp->name);
	printf("Employee number: %d \n", emp->empNum);
}

int main()
{
	List list;
	ListInit(&list);
	Employee* pemp;
	int i;

	/*4명의 데이터 저장*/
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 1228;
	strcpy(pemp->name, "이태현");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2222;
	strcpy(pemp->name, "신짱구");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3333;
	strcpy(pemp->name, "김철수");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4444;
	strcpy(pemp->name, "한유리");
	LInsert(&list, pemp);

	/*이태현 뒤로 3일 뒤 당직자는?*/
	printf("이태현 뒤로 3일 뒤 당직자는? \n");
	pemp = WhosNightDuty(&list, "이태현", 3);
	ShowEmployeeInfo(pemp);
	printf("\n");

	/*한유리 뒤로 15일 뒤 당직자는?*/
	printf("한유리 뒤로 15일 뒤 당직자는? \n");
	pemp = WhosNightDuty(&list, "한유리", 15);
	ShowEmployeeInfo(pemp);
	printf("\n");

	/*할당된 메모리의 전체 소멸*/
	if (LFirst(&list, &pemp))
	{
		free(pemp);

		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &pemp))
				free(pemp);
		}
	}
	return 0;
}