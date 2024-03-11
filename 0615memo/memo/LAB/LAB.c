#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int fibo(int n, int* F)
{
	if (n == 1 || n == 2) {
		printf("1 ");
		return 1;
	}

	if (F[n - 1] == 0)
		F[n - 1] = fibo(n - 1, F);
	if (F[n - 2] == 0)
		F[n - 2] = fibo(n - 2, F);

	printf("%d ", F[n - 1] + F[n - 2]);
	return F[n - 1] + F[n - 2];
}
int main(void)
{
	int n, i;
	int result;
	int* F;

	printf("몇 번째까지 피보나치 수열 : ");
	scanf("%d", &n);

	//memo초기화
	F = (int*)malloc(sizeof(int) * (n+1));

	for (int i = 1; i <= n; i++)
		F[i] = 0; //F[1]부터 유의미한 값을 넣음

	//printf("%d\n", fibo(n, F)); //메모와 함께 재귀함수 호출
	result=fibo(n,F);
	free(F);
}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int fibo(int n, int* M)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	else
//	{
//		M[n] = fibo(n - 1, M) + fibo(n - 2, M);
//	}
//	return M[n];
//}
//int main(void)
//{
//	int n, i;
//	int* memo;
//	
//	printf("몇 번째까지 피보나치 수열 : ");
//	scanf("%d", &n);
//	
//		//memo초기화
//	memo = (int*)malloc(sizeof(int) * (n + 1));
//	
//		for (int i = 1; i <= n; i++)
//			memo[i] = 0; //memo[1]부터 유의미한 값을 넣음
//	
//	printf("%d\n", fibo(n, memo)); //메모와 함께 재귀함수 호출
//	free(memo);
//}