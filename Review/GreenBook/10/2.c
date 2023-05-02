////
//// Created by 22490 on 2023/5/2.
////
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//typedef struct Node
//{
//	int val;
//	struct Node* next;
//	struct Node* prev;
//} Node;
//
//Node* reverseList(Node* head)
//{
//	Node* prev = NULL, * next = NULL, * cur = head;
//	while (cur)
//	{
//		next = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//	return prev;
//}
//
//Node* Create(int val)
//{
//	Node* p = malloc(sizeof(Node));
//	p->val = val;
//	p->next = NULL;
//}
//
//int main()
//{
//	Node* head, * cur;
//	int n;
//	head = cur = Create(-1);
//
//	do
//	{
//		scanf("%d", &n);
//		if (n == -1)
//		{
//			break;
//		}
//		else
//		{
//			cur->next = Create(n);
//			cur = cur->next;
//		}
//	} while (1);
//
//	cur = reverseList(head->next);
//	while (cur)
//	{
//		printf("%d ", cur->val);
//		cur = cur->next;
//	}
//
//	return 0;
//}