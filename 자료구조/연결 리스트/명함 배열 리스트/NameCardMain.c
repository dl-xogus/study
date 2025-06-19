#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main()
{
	List list;
	NameCard* pcard;
	ListInit(&list);

	pcard = MakeNameCard("이진수", "010-1111-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("한지영", "010-2222-5555");
	LInsert(&list, pcard);

	pcard = MakeNameCard("조수진", "010-3333-7777");
	LInsert(&list, pcard);

	// 한지영의 정보를 조회하여 출력
	printf("-----[한지영의 정보를 조회하여 출력]-----\n\n");
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "한지영"))
		{
			ShowNameCardInfo(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "한지영"))
				{
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}

	// 이진수의 정보를 조회하여 변경
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "이진수"))
		{
			ChangePhoneNum(pcard, "010-9999-9999");
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "이진수"))
				{
					ChangePhoneNum(pcard, "010-9999-9999");
					break;
				}
			}
		}
	}
	printf("[이진수의 정보를 조회하여 변경 완료]\n\n");

	// 조수진의 정보를 조회하여 삭제
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "조수진"))
		{
			pcard = LRemove(&list);
			free(pcard); 
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "조수진"))
				{
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}
	printf("[조수진의 정보를 조회하여 삭제 완료]\n\n");

	// 모든 사람의 정보 출력
	printf("-----[전체출력]-----\n\n");
	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);
		
		while (LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}
	return 0;
}