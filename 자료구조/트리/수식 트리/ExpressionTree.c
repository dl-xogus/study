#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ExpressionTree.h"
#include "ListBaseStack.h"
#include "BinaryTree2.h"

BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode* pnode;

	int explen = strlen(exp);
	int i;

	StackInit(&stack);

	for (i = 0; i < explen; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))				// 피연산자라면
		{
			SetData(pnode, exp[i] - '0');	// 문자를 정수로 바꿔서 저장
		}
		else								// 연산자라면
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}

		SPush(&stack, pnode);
	}

	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)	// 단말 노드라면
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));		// 왼쪽 서브 트리 계산
	op2 = EvaluateExpTree(GetRightSubTree(bt));		// 오른쪽 서브 트리 계산

	switch (GetData(bt))		// 연산자를 확인하여 연산을 진행
	{
	case '+':
		return op1 + op2;

	case '-':
		return op1 - op2;

	case '*':
		return op1 * op2;

	case '/':
		return op1 / op2;
	}

	return 0;
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);		// 피연산자 출력
	else
		printf("%c ", data);		// 연산자 출력
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt)
{
	InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}