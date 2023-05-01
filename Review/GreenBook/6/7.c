////
//// Created by 22490 on 2023/5/1.
////
//#include <stdio.h>
//#include <string.h>
//
//int findMax(char* str)
//{
//	int i, max = 0;
//	for (i = 0; str[i]; i++)
//		if (str[i] > str[max])
//			max = i;
//	return max;
//}
//
//int main()
//{
//	char str[100], b[10] = "xx", t[100] = { 0 };
//	gets(str);
//	int index = findMax(str);
//	strncpy(t, str, index + 1);
//	strcat(t, b);
//	strcat(t, str + index + 1);
//	strcpy(str, t);
//	printf("%s", str);
//
//	return 0;
//}
