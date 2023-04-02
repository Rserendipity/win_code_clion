//#include <stdio.h>
//#include <string.h>
//
//void insert(char* a, char* b)
//{
//	int i, len = strlen(a), min = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (a[i] > a[min])
//			min = i;
//	}
//	while (*b)
//	{
//		*(a + min) = *b;
//		b++;
//		min++;
//	}
//	*(a + min) = '\0';
//}
//
//int main()
//{
//	char str[30] = "abaaa";
//	char* pstr = "gg";
//	insert(str, pstr);
//	printf("%s", str);
//	return 0;
//}