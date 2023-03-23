//// 题目：将一个数组逆序输出。
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int i, t;
//	printf("原始数组是:\n");
//
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr[i]);
//
//	for (i = 0; i < 10 / 2; i++)
//	{
//		t = arr[i];
//		arr[i] = arr[10 - 1 - i];
//		arr[10 - 1 - i] = t;
//	}
//
//	printf("\n排序后的数组:\n");
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//	return 0;
//}