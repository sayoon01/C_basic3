#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, n, count = 0, last;
	long long sum = 1;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		sum *= i;
	}


	while (sum > 0) {
		last = sum % 10;
		if (last == 0) {
			count++;
		}
		else {
			break; // 실행시간 줄이기
		}
		sum /= 10;
	}

	printf("%d\n", count);
}
