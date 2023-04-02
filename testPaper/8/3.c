//#include <stdio.h>
//
//void myStrncat(char* score, char* dest, int n)
//{
//	int i;
//	while (*score)
//		score++;
//
//	for (i = 0; i < n && *dest; i++) {
//		*score = *dest;
//		score++;
//		dest++;
//	}
//	*score = '\0';
//}
//
//int main()
//{
//	char str[30] = "abaaa";
//	char* pstr = "ggrrrrr";
//	myStrncat(str, pstr, 5);
//	printf("%s", str);
//	return 0;
//}