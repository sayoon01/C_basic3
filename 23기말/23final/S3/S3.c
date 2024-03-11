//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//long fibo(int n, int* M,int k)
//{
//	if (n <= k)
//		return 1;
//	else
//	{
//		int sum = 0;
//		for (int i = 1; i <= k; i++)
//			sum += fibo(n - i, M, k);
//		M[n] = sum;
//	}
//	return M[n];
//}
//int main(void)
//{
//	int n, i, k;
//	int* memo;
//
//	//printf("몇 번째까지 피보나치 수열 : ");
//	scanf("%d %d", &n, &k);
//
//	//memo초기화
//	memo = (long*)malloc(sizeof(long) * (n + 1));
//
//	for (int i = 1; i <= n; i++)
//		memo[i] = 0; //memo[1]부터 유의미한 값을 넣음
//
//	printf("%d\n", fibo(n, memo, k)); //메모와 함께 재귀함수 호출
//	free(memo);
//}

#include <stdio.h>

int countMemo[MAXN+1][MAXM+1][MAXN*2+1]; // countMemo[i][j][k]는 i번째 숫자까지 선택했을 때, 길이가 j이고 k개의 짝수를 포함하는 수열의 개수를 저장

int generateSequences(int N, int M, int L, int currNum, int len, int evenCount) {
    if (len == M) {
        if (evenCount >= L) {
            countMemo[currNum][len][evenCount] = 1;
        }
        else {
            countMemo[currNum][len][evenCount] = 0;
        }
    }

    if (currNum > M) {
        countMemo[currNum][len][evenCount] = 0;
        return;
    }
    if (countMemo[currNum][len][evenCount] != -1) {
        return;
    }

    generateSequence(currNum + 1, len + 1, evenCount + (currNum % 2 == 0), N, M, L);
    generateSequence(currNum + 1, len, evenCount, N, M, L);

    countMemo[currNum][len][evenCount] = countMemo[currNum + 1][len + 1][evenCount * 2 + 1]
}

int countSequences(int N, int M, int L) {
    // 초기화: 모든 countMemo 배열 값은 -1로 설정
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= L; k++) {
                countMemo[i][j][k] = -1;
            }
        }
    }

    return generateSequences(N, M, L, 2, 0, 0);
}

int main() {
    int N, M, L;
    scanf("%d %d %d", &N, &M, &L);

    int count = countSequences(N, M, L);
    printf("%d\n", count);

    return 0;
}