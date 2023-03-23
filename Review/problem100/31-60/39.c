//// 题目：有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数组中。
//#include <stdio.h>
//
//int main()
//{
//	int arr[11]={1,4,6,9,13,16,19,28,40,100};
//	int n,i;
//	scanf("%d", &n);
//	for (i = 10; i >= 0; i--)
//	{
//		if (n > arr[i-1])
//		{
//			arr[i] = n;
//			break;
//		}
//		else
//		{
//			arr[i] = arr[i - 1];
//		}
//	}
//
//	for (i = 0; i < 11; i++)
//		printf("%d ", arr[i]);
//
//	return 0;
//}