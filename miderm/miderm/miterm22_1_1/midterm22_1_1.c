#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printbinary(int n, int k)
{
	if (n > 0)
	{
		printPalindrome(n / k, k);
		printf("%d ", n % k);
	}
}
int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	printbinary(n, k);
}