#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int calculateCombination(int n, int r, int** memo) {
	if (r == 0 || r == n)
		return 1;
	else {
		if (memo[n - 1][r - 1] == 0)
			memo[n - 1][r - 1] = calculateCombination(n - 1, r - 1, memo);

		if (memo[n - 1][r] == 0)
			memo[n - 1][r] = calculateCombination(n - 1, r, memo);

		return memo[n - 1][r - 1] + memo[n - 1][r];
	}
}

int main(void) {
	int combination, ** memo;
	int n, r, i, j;

	printf("Enter n and r: ");
	scanf("%d %d", &n, &r);

	memo = (int**)malloc(sizeof(int*) * (n + 1));
	for (i = 0; i <= n; i++) {
		memo[i] = (int*)malloc(sizeof(int) * (i + 1));
	}

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= i; j++)
			memo[i][j] = 0;
	}

	combination = calculateCombination(n, r, memo);
	printf("조합의 수: %d\n", combination);

	return 0;
}