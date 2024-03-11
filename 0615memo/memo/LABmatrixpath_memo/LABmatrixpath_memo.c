#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int matrixPath_memo(int** m, int r, int c, int i, int j,int **M)
{
	if (i == 0 && j == 0)
		return m[0][0];
	else if (i == 0) {
		if (M[0][j - 1] == 0)
			M[0][j - 1] = matrixPath_memo(m, r, c, 0, j - 1, M);
		return M[0][j - 1] + m[i][j];
	}
	else if (j == 0) {
		if (M[i - 1][0] == 0)
			M[i - 1][0] = matrixPath_memo(m, r, c, i - 1, 0, M);
		return M[i - 1][0] + m[i][j];

	}
	else
	{
		if (M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath_memo(m, r, c, i - 1, j, M);
		if (M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath_memo(m, r, c, i, j - 1, M);
		return (M[i - 1][j] < M[i][j - 1] ? M[i - 1][j] : M[i][j - 1]) + m[i][j];
	}

}
int main(void)
{
	int** m, ** M;
	int r, c;
	int i, j;

	scanf("%d %d", &r, &c);

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0; // memo 초기화
		}
	}

	printf("%d\n", matrixPath_memo(m, r, c, r - 1, c - 1, M));

	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
	}
	free(m);
	free(M);
}