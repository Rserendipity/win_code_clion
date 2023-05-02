////
//// Created by 22490 on 2023/5/1.
////
//#include <stdio.h>
//#include <string.h>
//
//int* findMax(int* a, int t, int* k)
//{
//	int i;
//	for (i = 0, *k = 0; i < t; i++)
//		if (a[i] > a[*k])
//			*k = i;
//	return a + *k;
//}
//
//int main()
//{
//	int arr[10] = { 12, 23, 34, 45, 56, 67, 78, 89, 11, 22 }, k, * add;
//	add = findMax(arr, 10, &k);
//	printf("%d %d %p", arr[k], k, add);
//	return 0;
//}