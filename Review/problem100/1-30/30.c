//// 题目：一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同。
//#include <stdio.h>
//
//int main()
//{
//	int n,i,j,arr[5], flag = 1;
//	i = j = 0;
//	scanf("%d", &n);
//	while (n)
//	{
//		arr[j] = n % 10;
//		j++;
//		n /= 10;
//	}
//	j--;
//	while (i < j)
//	{
//		if (arr[i] != arr[j])
//			flag = 0;
//		i++;
//		j--;
//	}
//	if (flag)
//		printf("是回文数\n");
//	else
//		printf("不是回文数\n");
//
//	return 0;
//}