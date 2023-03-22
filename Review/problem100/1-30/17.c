//// 题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
//#include <stdio.h>
//
//int main()
//{
//	char str[100];
//	int i, alphe = 0, space = 0, num = 0, other= 0;
//	gets(str);
//	for (i = 0; str[i]; i++)
//	{
//		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
//			alphe++;
//		else if (str[i] == ' ')
//			space++;
//		else if (str[i] >= '0' && str[i] <= '9')
//			num++;
//		else
//			other++;
//	}
//	printf("字母：%d 数字：%d 空格：%d 其他%d", alphe, space, num, other);
//	return 0;
//}