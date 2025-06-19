#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DBLinkedList.h"

int main()
{
	List list;
	ListInit(&list);
	int data;

	/*8개의 데이터 저장*/
	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);

	/*저장된 데이터의 조회*/
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		// 오른쪽 노드로 이동하며 데이터 조회
		while (LNext(&list, &data))
			printf("%d ", data);

		// 왼쪽 노드로 이동하며 데이터 조회
		while (LPrevious(&list, &data))
			printf("%d ", data);

		printf("\n");
	}
	return 0;
}