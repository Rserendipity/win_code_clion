// 题目：打印楼梯，同时在楼梯上方打印两个笑脸。

#include <stdio.h>

int main()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%c", 219);
		}
		printf("\n");
	}
	return 0;
}