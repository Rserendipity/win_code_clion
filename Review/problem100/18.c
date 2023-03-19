//// 题目：求s=a+aa+aaa+aaaa+aa...a的值
//// 其中a是一个数字。
//// 例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
//#include <stdio.h>
//
//int main()
//{
//	int a,n,i,j,s = 0,t;
//	scanf("%d %d",&a,&n);
//	for (i = 0; i < n; i++)
//	{
//		t = a;
//		for(j = 0; j < i; j++)
//			t = 10 * t + a;
//
//		s +=t;
//	}
//	printf("%d\n", s);
//	return 0;
//}