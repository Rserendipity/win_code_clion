//// 题目：古典问题（兔子生崽）：
//// 有一对兔子，从出生后第3个月起每个月都生一对兔子
//// 小兔子长到第三个月后每个月又生一对兔子
//// 假如兔子都不死，问每个月的兔子总数为多少？（输出前40个月即可）
//#include <stdio.h>
//
//int main()
//{
//	int num[40] = { 1, 1, 2 }, i;
//	for (i = 3; i < 40; i++)
//	{
//		// 本月的兔子数量是 上月的数量 + 上上月的数量
//		num[i] = num[i - 1] + num[i - 2];
//	}
//	for (i = 0; i < 40; i++)
//	{
//		printf("第%d个月的兔子数量为：%d\n", i + 1, num[i]);
//	}
//	return 0;
//}