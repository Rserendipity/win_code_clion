#include <stdio.h>

//题目：输入某年某月某日，判断这一天是这一年的第几天？

int isPrime(int year)
{
	return year%400 == 0 || (year%100 != 0 && year%4 == 0);
}

int main()
{
	int months[13] = { 0, 0, 31, 59, 89, 120, 150, 181, 212, 242, 273, 303, 334};
	int year = 0, month = 0, day = 0, result = 0;
	scanf("%d%d%d", &year, &month, &day);
	result = months[month];
	if (month>2 && isPrime(year)){
		result += 1;
	}
	printf("这一天是第%d天", result);
	return 0;
}
