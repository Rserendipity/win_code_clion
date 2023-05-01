////
//// Created by 22490 on 2023/5/1.
////
//#include <stdio.h>
//#include <math.h>
//
//int isPrefect(int n)
//{
//	int arr1[10] = { 0 }, arr2[10] = { 0 };
//	int i, j = 0;
//	for (i = n * n; i; i /= 10) // 将n^2倒序放入到arr1中
//		arr1[j++] = i % 10;
//
//	j = 0;
//	for (i = n; i; i /= 10) // 将n倒序放入到arr2中
//		arr2[j++] = i % 10;
//
//	for (i = 0; i < j; i++) // 比较arr2和arr1中尾数，看是否一致
//		if (arr1[i] != arr2[i]) // 出现不一致，就是尾数不同的情况，返回0
//			return 0;
//	return 1; // 遍历完成后则返回1
//}
//int main()
//{
//	int i;
//	for (i = 1; i <= 999; i++)
//		if (isPrefect(i))
//			printf("%d ", i);
//
//	return 0;
//}
