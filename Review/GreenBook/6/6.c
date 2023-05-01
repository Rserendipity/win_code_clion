////
//// Created by 22490 on 2023/5/1.
////
//#include <stdio.h>
//#include <math.h>
//
//#define N 10
//
//int main()
//{
//	int arr[N][N], n = 4, i, j, m, k = 1;
//	if (n % 2 == 0)
//		m = n / 2;
//	else
//		m = n / 2 + 1;
//	for (i = 0; i < m; i++)
//	{
//		// 从左至右
//		for (j = i; j < n - i; j++)
//			arr[i][j] = k++;
//
//		// 从上到下
//		for (j = i + 1; j < n - i; j++)
//			arr[j][n - 1 - i] = k++;
//
//		// 从右至左
//		for (j = n - i - 2; j >= i; j--)
//			arr[n - i - 1][j] = k++;
//
//		// 从下至上
//		for (j = n - i - 2; j > i; j--)
//			arr[j][i] = k++;
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//			printf("%3d ", arr[i][j]);
//		printf("\n");
//	}
//
//	return 0;
//}
