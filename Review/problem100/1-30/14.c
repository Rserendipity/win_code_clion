//// 题目：将一个正整数分解质因数。
//// 例如：输入90,打印出90=2*3*3*5。
//#include <stdio.h>
//
//int main()
//{
//	int input,n;
//	scanf("%d", &input);
//	n = 2;
//	while (input != 1)
//	{
//		if (input % n == 0)
//		{
//			input /= n;
//			printf("%d",n);
//			if (input != 1)
//				printf("*");
//		}
//		else
//			n++;
//	}
//	return 0;
//}