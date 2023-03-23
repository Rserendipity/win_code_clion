////
//// Created by 22490 on 2023/3/20.
////
//#include <stdio.h>
//#include <string.h>
//
//void addSpace(char* str)
//{
//	int n = strlen(str), i, j;
//	// 在2n处补上'\0'结尾
//	str[n + n] = '\0';
//	// i 控制当前的字符要放在哪里
//	// j 控制当前放的是 空格 还是 原字符串内容
//	// 前置--的n用来控制放入的字符，前置用来跳过原字符串的 '\0'
//	for (i = n + n - 1, j = 0; i >= 0; i--, j++)
//		if (j % 2 == 0)
//			str[i] = ' ';
//		else
//			str[i] = str[--n];
//}
//
//int main()
//{
//	char str[100] = {'a','b','\0', 'a', 'a', 'a'};
//	addSpace(str);
//	printf("%s", str);
//	return 0;
//}