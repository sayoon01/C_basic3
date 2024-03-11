#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//unsigned long long reverseNum(unsigned long long n)
//{
//	unsigned long long ret = 0, remainer = 0;
//
//	while (n != 0)
//	{
//		remainer = n % 10;
//		ret *= 10;
//		ret = ret + remainer;
//		n = n / 10;
//	}
//	return ret;
//}
//
//int main(void)
//{
//	unsigned long long inputNum, n1, n2;
//	int cnt = 0;
//
//	scanf("%llu", &inputNum);
//	n1 = inputNum;
//	n2= reverseNum(n1);
//
//	while (n1!=n2) {
//		cnt++;
//		n1 = n1 + n2;
//		n2= reverseNum(n1);
//
//		if (cnt >= 1000) {
//			printf("NaN\n");
//			return 0;
//		}
//	}
//
//	printf("%d %llu\n", cnt, n1);
//	return 0;
//}
int reverseNum(int n)
{
	int remainer = 0;

	while (n > 0)
	{
		remainer = remainer * 10 + n % 10;
		n /= 10;
	}
	return remainer;
}
int main(void)
{
	int cnt = 0;//몇 번 뒤집는지??
	int n, reverse_n;
	int sum;
	
	scanf("%d", &n);

	while (cnt < 1000)
	{
		cnt++;
		reverse_n = reverseNum(n);
		sum = n + reverse_n;
		if (sum == reverseNum(sum)) { // 뒤집어서 더한 수가 palindrome인지 판별
			printf("%d %d\n", cnt, sum);
			return 0;
		}
		else {
			n = sum;
		}
	}
	printf("NaN\n");
	return 0;
}










