//// 题目：输入两个正整数m和n，求其最大公约数和最小公倍数。
//#include <stdio.h>
//
//int maxYue(int m, int n)
//{
//	// 辗转相除法，求的最大公倍数
//	if (m % n == 0)
//		return n;
//	else
//		return maxYue(n, m % n);
//}
//
//int main()
//{
//	int m, n, t, min, max;
//	scanf("%d %d", &m, &n);
//	max = maxYue(m, n);
//	min = m * n / max; //最小公倍数为两数的乘积除以最大公倍数
//	printf("最大公约为：%d，最小公倍数为：%d", max, min);
//	return 0;
//}