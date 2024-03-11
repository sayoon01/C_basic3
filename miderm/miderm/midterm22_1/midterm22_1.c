
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int findBinary(char p[], int n, int k)
{
	int tmp;
	int i = 0;
	while (n > 0)
	{
		tmp = n % k;
		if (tmp > 9)
		{
			p[i++] = tmp + '0' + 7;
		}
		else
		{
			p[i++] = tmp + '0';
		}
		n /= k;
	}
	p[i] = '\0';
	return i;
}
int is_palindrome(char p[],int size)
{
	for (int i = 0; i < size / 2; i++)
		if (p[i] != p[size - 1 - i])
			return 0;
	return 1;
}
int main(void)
{
	char p[100];
	int num;
	int size, k;

	scanf("%d %d", &num, &k);
	
	size = findBinary(p, num, k);
	printf("%d", is_palindrome(p,size));
}
