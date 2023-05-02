////
//// Created by 22490 on 2023/5/1.
////
//#include <stdio.h>
//#include <string.h>
//
//void reverse(int arr[], int begin, int cnt)
//{
//	int end = begin + cnt, t;
//	while (begin < end)
//	{
//		t = arr[begin];
//		arr[begin] = arr[end];
//		arr[end] = t;
//		begin++, end--;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, i;
//	reverse(arr, 3, 5);
//	for (i = 0; i < 10; i++)
//		printf("%d ", arr[i]);
//
//	return 0;
//}