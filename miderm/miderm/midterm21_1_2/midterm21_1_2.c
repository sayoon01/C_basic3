//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//int main(void)
//{
//	char s1[100], s2[100];
//	int n1 = 0, n2 = 0;
//	int i, j;
//	int carry = 0;
//	int count = 0;
//
//	scanf("%s %s", s1, s2);
//	i = strlen(s1) - 1;
//	j = strlen(s2) - 1;
//	while (i>=0 || j>=0)
//	{
//		if (i >=0)
//			n1 = s1[i] - '0';
//		else
//			n1 = 0;
//
//		if (j >=0)
//			n2 = s2[j] - '0';
//		else
//			n2 = 0;
//
//		if (n1 + n2 + carry >= 10)
//		{
//			carry = 1;
//			count++;
//		}
//		else
//			carry = 0;
//		i--;
//		j--;
//	}
//
//	printf("%d", count);
//} 
// 큰 수의 덧셈
//큰수의 덧셈
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char data1[100], data2[100];
	int idx1, idx2;
	int num1, num2, carry = 0;
	int count = 0;
	scanf("%s %s", data1, data2);
	idx1 = strlen(data1) - 1;
	idx2 = strlen(data2) - 1;

	while (idx1 >= 0 || idx2 >= 0)
	{
		num1 = data1[idx1] - '0';
		num2 = data2[idx2] - '0';

		if (idx1 < 0)
			num1 = 0;
		if (idx2 < 0)
			num2 = 0;

		if (num1 + num2 + carry >= 10)
		{

			count++;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		idx1--;
		idx2--;
	}
	printf("%d\n", count);
}