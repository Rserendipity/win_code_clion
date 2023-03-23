////
//// Created by 22490 on 2023/3/20.
////
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 }, i, j, n, flag = 1;
//
//	scanf("%d", &n);
//	for (i = 0; n; i++)
//	{
//		arr[i] = n % 10;
//		n /= 10;
//	}
//
//	for (j = 0, i--; j < i; i--, j++)
//	{
//		if (arr[i] != arr[j])
//		{
//			flag = 0;
//			break;
//		}
//	}
//	if (flag)
//		printf("是");
//	else
//		printf("不是");
//
//	return 0;
//}