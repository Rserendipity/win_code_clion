////
//// Created by 22490 on 2023/3/20.
////
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int n,i,j,k,end;
//	scanf("%d", &n);
//	// 开辟n个空间的数组
//	int *parr = (int*)malloc(sizeof(int)*n);
//	// 在动态数组中填入1到n
//	for (i = 0; i < n; i++)
//		parr[i] = i+1;
//
//	// 寻找时，循环n - 1次
//	k = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		j = 1;
//		while (j != 3) // 报数到3的时候停止
//		{
//			if (k >= n) // 超出下标时，将下标归零
//			{
//				k = 0;
//				continue;
//			}
//
//			if (parr[k] != 0) // 不为零的时候，进行计数
//			{
//				j++;
//				k++;
//			}
//			else // 为零的时候往后寻找
//			{
//				k++;
//			}
//		}
//		parr[k] = 0; // 置零即出队
//	}
//
//	// 寻找不为0的那个，即为答案
//	for (i = 0; i < n; i++)
//		if (parr[i] != 0)
//			end = parr[i];
//
//	printf("这个人是：%d", end);
//	free(parr); // 释放开辟的空间
//	return 0;
//}