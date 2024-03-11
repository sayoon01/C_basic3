#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 0
#define LEFT 1
#define UP 2

#define NOT_AVAILABLE 0
#define AVAILABLE 1

int matrixPath_memo(int** m, int r, int c, int i, int j, int** M, int** M1, int** bp)
{
	if (i == 0 && j == 0)
		return m[0][0];

	else if (i == 0) {
		if (M1[0][j - 1] == NOT_AVAILABLE) {
			M[0][j - 1] = matrixPath_memo(m, r, c, 0, j - 1, M, M1, bp);
			M1[0][j - 1] == AVAILABLE;
			bp[0][j - 1] = LEFT;
		}
		return M[0][j - 1] + m[i][j];
	}
	else if (j == 0) {
		if (M1[i - 1][0] == NOT_AVAILABLE) {
			M[i - 1][0] = matrixPath_memo(m, r, c, i - 1, 0, M, M1);
			M1[i - 1][0] == AVAILABLE;
			bp[i - 1][0] = UP;
		}
		return M[i - 1][0] + m[i][j];

	}
	else
	{
		if (M1[i - 1][j] == NOT_AVAILABLE) {
			M[i - 1][j] = matrixPath_memo(m, r, c, i - 1, j, M, M1);
			M1[i - 1][j] == AVAILABLE;
			bp[i - 1][j] = UP;
		}
		if (M1[i][j - 1] == NOT_AVAILABLE) {
			M[i][j - 1] = matrixPath_memo(m, r, c, i, j - 1, M, M1);
			M1[i][j - 1] == AVAILABLE;
			bp[i][j - 1] = LEFT;
		}
		return (M[i - 1][j] < M[i][j - 1] ? M[i - 1][j] : M[i][j - 1]) + m[i][j];
	}

}
int main(void)
{
	int** m, ** M, ** M1, ** bp;
	int r, c;
	int i, j;

	scanf("%d %d", &r, &c);

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	M1 = (int**)malloc(sizeof(int*) * r);
	bp = (int**)malloc(sizeof(int*) * r);

	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
		M1[i] = (int*)malloc(sizeof(int) * c);
		bp[i] = (int**)malloc(sizeof(int*) * c);
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M1[i][j] == NOT_AVAILABLE;// memo 초기화 음수에서는 M[i][j]=0 이 아니라 M1[i][j]=0 !!!!!
			bp[i][j] = DEFAULT;
		}
	}

	printf("%d\n", matrixPath_memo(m, r, c, r - 1, c - 1, M, M1, bp));

	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
		free(M1[i]);
		free(bp[i]);
	}
	free(m);
	free(M);
	free(M1);
	free(bp);
}