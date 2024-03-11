//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int transformR(int n,char a[], int  k)
//{
//	static int i = 0;
//
//	if (n != 0)
//	{
//		transformR(n / k, a, k);
//		int tmp = n % k;
//		if(tmp>=10)
//		{
//			a[i] = tmp + '0' + 7;
//		}
//		else
//			a[i] = tmp + '0';
//
//		i++;
//	}
//	//a[i] = '\0';
//	return i;
//}
//void testPrint(char a[], int size)
//{
//	for (int i = 0; i < size; i++)
//		printf("%c ", a[i]);
//	return;
//}
//int isPalindrome(char a[], int size)
//{
//	for (int i = 0; i < size / 2; i++)
//	{
//		if (a[i] != a[size - 1 - i])
//			return 0;
//	}
//	return 1;
//}
//int main(void)
//{
//	int n, k;
//	char a[100], size;
//
//	scanf("%d %d", &n, &k);
//
//	size = transformR(n, a, k);
//	printf("%d\n", size);
//	testPrint(a, size);
//
//	int s = isPalindrome(a, size);
//	printf("\n%d", s);
//}

// palindrome 판별
#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, size;
	int n, k;
	char num1[64];
	char num2[64];

	scanf_s("%d %d", &n, &k);

	i = 0;
	while (n != 0)
	{
		if ((n % k) >= 10)
			num1[i++] = (n % k - 10) + 'A';
		else
			num1[i++] = n % k + '0';
		n /= k;
	}
	num1[i] = '\0';
	size = strlen(num1);

	for (i = 0; i < size; i++)
	{
		num2[i] = num1[size - 1 - i];
	}
	num2[i] = '\0';

	if (!strcmp(num1, num2))
		printf("1");
	else
		printf("0");
}