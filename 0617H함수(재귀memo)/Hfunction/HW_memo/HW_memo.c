//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int H(int n, int* M)
//{
//	int i;
//	int sum = 0;
//
//	if (n == 0 || n == 1)
//		return 1;
//
//	for (i = 0; i < n; i++)
//	{
//		if (M[i] == 0)
//			M[i] = H(i, M);
//		if (M[n - 1 - i] == 0)
//			M[n - 1 - i] = H(n - 1 - i, M);
//
//		sum += M[i] * M[n - 1 - i];
//		//sum += H(i) * H(n - 1 - i);
//	}
//
//	return sum;
//}
//int main(void)
//{
//	int n;
//	int* M;
//
//	printf("0보다 큰 정수 : ");
//	scanf("%d", &n);
//
//	M = (int*)malloc(sizeof(int) * (n + 1));
//
//	for (int i = 0; i < n+1; i++)
//		M[i] = 0;
//
//	printf("결과는 %d\n", H(n, M));
//
//	free(M);
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int H(int n, int* memo)
{
    int i;
    int sum = 0;

    if (memo[n] != 0)
        return memo[n];

    if (n == 0 || n == 1)
        return 1; 

    for (i = 0; i < n; i++) {
        sum += H(i, memo) * H(n - 1 - i, memo);
    }

    memo[n] = sum;
    return memo[n];

}
int main(void)
{
    int n, i;
    int* memo;
    printf("0보다 큰 정수:");
    scanf("%d", &n);

    memo = (int*)malloc(sizeof(int) * (n + 1)); // 메모공간 (n+1)!!
    for (i = 0; i < n + 1; i++)
        memo[i] = 0; // 메모 초기화
   
    printf("결과는 %d\n", H(n, memo));
    free(memo);
    return 0;
}