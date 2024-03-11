#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int calculateReverse(int n) {
    int reverse = 0;
    while (n > 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return reverse;
}

int main() {
    int n, reversed_n;
    int sum = 0;
    int count = 1;

    scanf("%d", &n);

    while (count <= 1000) {
        reversed_n = calculateReverse(n);
        sum = n + reversed_n;

        if (sum == calculateReverse(sum)) { // palindrome인 경우
            printf("%d %d", count, sum);
            return 0;
        }
        else { // palindrome이 아닌 경우
            n = sum;
            count++;
        }
    }
    printf("NaN\n");

    return 0;
}
