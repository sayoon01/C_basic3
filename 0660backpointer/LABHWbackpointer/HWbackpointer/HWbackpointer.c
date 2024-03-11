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
	if (M1[i][j] != 0)
		return M[i][j];

	M1[i][j] = 1;

	if (i == 0 && j == 0) {
		M[i][j] = m[i][j];
		bp[i][j] = DEFAULT;
		return M[i][j];
	}
	else if (i == 0) {
		M[i][j] = matrixPath_memo(m, r, c, i, j - 1, M, M1, bp) + m[i][j];
		bp[i][j] = LEFT;
		return M[i][j];
	}
	else if (j == 0) {
		M[i][j] = matrixPath_memo(m, r, c, i - 1, j, M, M1, bp) + m[i][j];
		bp[i][j] = UP;
		return M[i][j];
	}
	else
	{
		int a, b;
		a = matrixPath_memo(m, r, c, i - 1, j, M, M1, bp);
		b = matrixPath_memo(m, r, c, i, j - 1, M, M1, bp);

		if (a < b)
			bp[i][j] = UP;
		else
			bp[i][j] = LEFT;

		M[i][j] = ((a < b) ? a : b) + m[i][j];
		return M[i][j];
	}

}
void print_path(int i, int j, int** BP)
{
	if (BP[i][j] == UP)
		print_path(i - 1, j, BP);
	else if (BP[i][j] == LEFT)
		print_path(i, j - 1, BP);
	printf("<%d, %d> ", i, j);
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
		bp[i] = (int*)malloc(sizeof(int) * c);
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M1[i][j] = 0; // memo 초기화 음수에서는 M[i][j]=0 이 아니라 M1[i][j]=0 !!!!!
		}
	}

	printf("%d\n", matrixPath_memo(m, r, c, r - 1, c - 1, M, M1, bp));
	print_path(r - 1, c - 1, bp);
	/*for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%d ", bp[i][j]);
		printf("\n");
	}*/

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