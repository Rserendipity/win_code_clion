//#include <stdio.h>
//
//int find(const int* a, int n, int target)
//{
//	int i = 0, j = n - 1, mid = (i + j) / 2;
//	while (i <= j)
//	{
//		if (a[mid] == target)
//			return mid;
//		else if (a[mid] > target)
//			j = mid - 1;
//		else
//			i = mid + 1;
//
//		mid = (i + j) / 2;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//	int index = find(arr, 10, -1);
//
//	if (index == -1)
//		printf("没找到\n");
//	else
//		printf("找到了，下标为%d", index);
//	return 0;
//}