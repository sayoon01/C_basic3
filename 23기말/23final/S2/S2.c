#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long fibo(long n, long * M)
{
	if (n == 1 || n == 2 || n == 3)
		return 1;
	else
	{
		M[n] = fibo(n - 1, M) + fibo(n - 2, M) + fibo(n - 3, M);
	}
	return M[n];
}
int main(void)
{
	long n, i;
	long* memo;
	
	//printf("몇 번째까지 피보나치 수열 : ");
	scanf("%ld", &n);
	
		//memo초기화
	memo = (long*)malloc(sizeof(long) * (n+ 1));
	
		for (long i = 1; i <= n; i++)
			memo[i] = 0; //memo[1]부터 유의미한 값을 넣음
	
	printf("%ld\n", fibo(n, memo)); //메모와 함께 재귀함수 호출
	free(memo);
}