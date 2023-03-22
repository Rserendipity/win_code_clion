//// 题目：打印出如下图案（菱形）。
////   *
////  ***
//// *****
////*******
//// *****
////  ***
////   *
//#include <stdio.h>
//
//int main()
//{
//	int line,i,j;
//	scanf("%d", &line);
//
//	for (i = 0; i < line; i++)
//	{
//		for (j = 0; j < line - i - 1; j++)
//			printf(" ");
//		for (j = 0; j < 2*i+1; j++)
//			printf("*");
//		printf("\n");
//	}
//	for (i = 0; i < line - 1; i++)
//	{
//		for (j = 0; j <= i; j++)
//			printf(" ");
//		for (j = 0; j < (line - i - 1) * 2 - 1; j++)
//			printf("*");
//		printf("\n");
//	}
//
//	return 0;
//}