////
//// Created by 22490 on 2023/3/19.
////
//#include <stdio.h>
//
//void swap(int* pa, int* pb)
//{
//	int t = *pa;
//	*pa = *pb;
//	*pb = t;
//}
//
//int main()
//{
//	int arr[10][10] = {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
//	int n, i, j;
//	scanf("%d", &n);
//	for (i = 1; i < n; i++)
//	{
//		for (j = 0; j < i; j++)
//		{
//			swap(&arr[i][j], &arr[j][i]);
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}