//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//int array_length(char arr[]);
//int main(void)
//{
//	int lastIndex;
//	char num[52];
//
//	scanf("%s", num);
//	lastIndex = array_length(num) - 1;
//	if (num[lastIndex] % 2 == 0)
//		printf("1");
//	else
//		printf("0");
//}
//int array_length(char arr[])
//{
//	int len;
//	for (len = 0; arr[len] != '\0'; len++);
//	return len;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char data[55];
	int lastIndex, lastNum;

	scanf("%s", data);

	lastIndex = strlen(data) - 1;
	lastNum = data[lastIndex] - '0';

	if (lastNum % 2 == 0)
		printf("1");
	else
		printf("0");
}