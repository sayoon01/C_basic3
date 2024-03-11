#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct Coefficient {
	int F1;
	int F0;
	int flag;
};

struct Coefficient fibo(int n,struct Coefficient *memo)
{
	struct Coefficient ret;

	if (memo[n].flag != 0)
		return memo[n];
	memo[n].flag = 1;

	if(n == 0) {
		ret.F1 = 0;
		ret.F0 = 1;
		memo[n] = ret;
		return ret;
	}
	else if (n == 1) {
		ret.F1 = 1;
		ret.F0 = 0;
		memo[n] = ret;
		return ret;
	}
	else {
		struct Coefficient fn_1;
		struct Coefficient fn_2;

		fn_1 = fibo(n - 1,memo);
		fn_2 = fibo(n - 2, memo);

		ret.F1 = fn_1.F1 + fn_2.F1;
		ret.F0 = fn_1.F0 + fn_2.F0;
		memo[n] = ret;
		return ret;
	}
}
int main(void)
{
	int n;
	struct Coefficient *memo;
	struct Coefficient ret;

	printf("몇 번째까지 피보나치 수열 : ");
	scanf("%d", &n);

	memo = (struct Coefficient*)malloc(sizeof(struct Coefficient) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		memo[i].flag = 0;
	}
	ret = fibo(n, memo);

	printf("%d %d", memo[n].F1, memo[n].F0);

	free(memo);
	return 0;
}
