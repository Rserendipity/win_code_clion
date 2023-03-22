//// 题目：打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。
//// 例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i,tmp,index,arr[3];
//	for (i = 100; i <= 999; i++)
//	{
//		tmp = i;
//		index = 0;
//		while(tmp)
//		{
//			arr[index++] = tmp%10;
//			tmp/=10;
//		}
//		if (pow(arr[0],3) + pow(arr[1],3) + pow(arr[2],3) == i)
//			printf("%d\n",i);
//	}
//	return 0;
//}