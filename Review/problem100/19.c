//// 题目：一个数如果恰好等于它的因子之和，这个数就称为"完数"。
//// 例如6=1＋2＋3.编程找出1000以内的所有完数。
//#include <stdio.h>
//
//int isPerfect(int n)
//{
//	int sum = 0, i;
//	for (i = 1; i < n; i++)
//	{
//		if (n % i == 0)
//			sum += i;
//	}
//	return sum == n;
//}
//
//int main()
//{
//	int i;
//	for (i = 1; i <= 1000; i++)
//	{
//		if (isPerfect(i))
//			printf("%d ", i);
//	}
//	return 0;
//}