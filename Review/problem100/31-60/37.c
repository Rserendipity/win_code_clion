//// 题目：对10个数进行排序。
//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(const void* pa, const void* pb)
//{
//	return *(int*)pa - *(int*)pb;
//}
//
//void BubbleSort(int* arr, int n)
//{
//	int i, j;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int t = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = t;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[10], i;
//	for (i = 0; i < 10; i++)
//		scanf("%d", &arr[i]);
//
//	// 库函数
//	// qsort(arr, 10, 4, cmp);
//
//	BubbleSort(arr, 10);
//
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr[i]);
//
//	return 0;
//}