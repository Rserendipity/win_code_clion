//// 题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。
//#include <stdio.h>
//
//int main()
//{
//	double sum = 0, son = 2, mom = 1;
//	int i;
//	for (i = 1; i <= 20; i++)
//	{
//		sum += son/mom;
//		son = son + mom;
//		mom = son - mom;
//	}
//	printf("%lf", sum);
//	return 0;
//}