//// 题目：给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。
//#include <stdio.h>
//
//int main()
//{
//	int n, i, arr[5], cnt;
//	scanf("%d", &n);
//	i = 0, cnt = 0;
//
//	while (n)
//	{
//		arr[i] = n % 10;
//		n /= 10;
//		cnt++;
//		i++;
//	}
//
//	printf("有%d位\n", cnt);
//
//	for (i = 0; i < cnt; i++)
//		printf("%d ", arr[i]);
//
//	return 0;
//}