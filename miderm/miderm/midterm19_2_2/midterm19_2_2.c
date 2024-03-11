//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//void printOneOrZero(int x);
//int threeRslt(char arr[]);
//int fourRslt(char arr[], int lastIdx);
//int array_lastIndex(char arr[]);
//
//int main(void)
//{
//	int rslt = 0;
//	int lastIndex;
//	char num[81];
//
//	scanf("%s", num);
//	lastIndex = array_lastIndex(num);
//
//	rslt = num[lastIndex] - '0';
//	printOneOrZero(rslt % 2);
//
//	rslt = threeRslt(num);
//	printOneOrZero(rslt % 3);
//
//	rslt = fourRslt(num, lastIndex);
//	printOneOrZero(rslt % 4);
//	
//	rslt = num[lastIndex] - '0';
//	printOneOrZero(rslt % 5);
//}
//int array_lastIndex(char arr[])
//{
//	int len;
//	for (len = 0; arr[len] != '\0'; len++);
//	return len - 1;
//}
//int threeRslt(char arr[])
//{
//	int total = 0;
//	for (int i = 0; arr[i] != '\0'; i++)
//		total += (arr[i] - '\0');
//	return total;
//}
//int fourRslt(char arr[], int lastIdx)
//{
//	return (arr[lastIdx - 1] - '0') * 10 + arr[lastIdx] - '0';
//}
//void printOneOrZero(int x)
//{
//	if (x == 0)
//		printf("1");
//	else
//		printf("0");
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//void print_1or0(int x)
//{
//	if (x == 0)
//		printf("1");
//	else
//		printf("0");
//}
//int main(void)
//{
//	char data[81];
//	int lastIndex;
//	int n;
//	int sum = 0;
//
//	scanf("%s", data);
//
//	lastIndex = strlen(data) - 1;
//	n = data[lastIndex] - '0';
//	print_1or0(n % 2);
//
//	for (int i = 0; data[i] != '\0'; i++)
//		sum += (data[i] - '0');
//	print_1or0(sum % 3);
//
//	n = (data[lastIndex - 1] - '0') * 10 + data[lastIndex] - '0';
//	print_1or0(n % 4);
//
//	n = data[lastIndex] - '0';
//	print_1or0(n % 5);
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void print1_0(int n);
int main(void)
{
	char num[55];
	int lastIndex, rslt;

	scanf("%s", num);

	lastIndex = strlen(num) - 1;
	rslt = num[lastIndex] - '0'; // 문자를 숫자로 변환
	print1_0(rslt % 2);

	rslt = 0;
	for (int i = 0; num[i] != '\0'; i++)
		rslt += (num[i] - '0'); // 문자를 숫자로 변환
	print1_0(rslt % 3);

	rslt = num[lastIndex] - '0' + (num[lastIndex - 1] - '0') * 10; // 문자를 숫자로 변환
	print1_0(rslt % 4);
	
	rslt = num[lastIndex] - '0';// 문자를 숫자로 변환
	print1_0(rslt % 5);

	return 0;
}
void print1_0(int n)
{
	if (n == 0)
		printf("1");
	else
		printf("0");
}