//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int digitofNum(int n)
//{
//	int count = 0;
//	while (n != 0)
//	{
//		n /= 10;
//		count++;
//	}
//	return count;
//}
//int main(void)
//{
//	int n;
//
//	scanf("%d", &n);
//	printf("%d", digitofNum(n));
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int lengthofNum(int num)
//{
//	int i, len;
//
//	len = 0;
//	for (i = 1; i <= num; i++) {
//		len += digitofNum(i);
//	}
//	return len;
//}
//int digitofNum(int n)
//{
//	int count = 0;
//	while (n != 0)
//	{
//		n /= 10;
//		count++;
//	}
//	return count;
//}
//int main(void)
//{
//	int num;
//
//	scanf("%d", &num);
//	printf("%d", lengthofNum(num));
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int digits(int n)
{
	int num_of_digits = 0;
	while (n != 0)
	{
		n /= 10;
		num_of_digits++;
	}
	return num_of_digits;
}
int kth_digit(int n,int k)
{
	int i = 0;
	int ret;
	
	for (i = 0; i < k; i++) {
		ret = n % 10;
		n /= 10;
	}
	return ret;
}
void solution(int n)
{
	int i = 0;
	int t_digits = 0;
	while (t_digits < n)
	{
		i++;
		t_digits = t_digits + digits(i);
	}

	if (i < 10)
		printf("%d", i);
	else
		printf("%d",kth_digit(i,t_digits-n+1));
}
int main(void) {
	int n;

	scanf("%d", &n);
	solution(n);
}