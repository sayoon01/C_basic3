#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main(void)
//{
//	int n1, n2;
//	int carry = 0, carry_cnt = 0;
//
//	scanf("%d %d", &n1, &n2);
//
//
//	while (n1 != 0 || n2 != 0)
//	{
//
//		if (n1 % 10 + n2 % 10 + carry >= 10) { // 10이상은 carry발생
//			carry_cnt++;
//			carry = 1;// carry숫자 다음 자리수에 전달
//		}
//		else
//			carry = 0;
//
//		n1 /= 10;
//		n2 /= 10;
//	}
//	printf("%d\n", carry_cnt);
//
//}
