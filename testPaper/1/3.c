//
// Created by 22490 on 2023/3/18.
//
#include <stdio.h>

void myStrcat(char* dest, const char* source)
{
	while (*dest)
		dest++;
	while (*dest = *source)
	{
		dest++;
		source++;
	}
}

int main()
{
	char str[100] = "abc";
	char* p = "def";
	myStrcat(str, p);
	printf("%s", str);
	return 0;
}