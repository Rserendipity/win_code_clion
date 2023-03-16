#include <stdio.h>
#include <math.h>
// 题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？

int main()
{
	int i = 0;
	for (i;; i++)
	{
		if ((double)(int)sqrt(i + 100) == sqrt(i + 100)
			&& (double)(int)sqrt(i + 268) == sqrt(i + 268))
		{
			printf("num is:%d\n", i);
			break;
		}
	}
	return 0;
}