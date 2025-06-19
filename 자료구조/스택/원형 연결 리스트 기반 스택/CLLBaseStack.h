#ifndef __CLL_STACK_H__
#define __CLL_STACK_H__

#include "CLinkedList.h"

#define TRUE	1
#define FALSE	0

typedef struct _listStack
{
	List* plist;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);			// ������ �ʱ�ȭ
int SIsEmpty(Stack* pstack);			// ������ ������� Ȯ��

void SPush(Stack* pstack, Data data);	// ������ push ����
Data SPop(Stack* pstack);				// ������ pop ����
Data SPeek(Stack* pstack);				// ������ peek ����

#endif