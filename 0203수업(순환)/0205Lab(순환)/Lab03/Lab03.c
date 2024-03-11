#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int H(int n)
//{
//	int i, sum;
//	if (n == 0 || n == 1)
//		return 1;
//	else {
//		sum = 0;
//		for (i = 0; i < n; i++)
//			sum += (H(i) * H(n - i - 1));
//		return sum;
//	}
//}
//int main(void)
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d\n", H(n));
//}
int H(int num)
{
	int result;
	if (num == 0 || num == 1)
		return 1;
	else
	{
		result = 0;
		for (int i = 0; i < num; i++)
			result += H(i) * H(num - 1 - i);
	}
	return result;
}
int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d", H(n));
}
