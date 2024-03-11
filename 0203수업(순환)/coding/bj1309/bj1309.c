#define _CRT_SECURE_NO_WARNINGS
#define ROW_MAX 100000
#include <stdio.h>

int union_cnt(int n, int r);
int main(void)
{
	int table[ROW_MAX][2];
	int row;
	int cnt;

	scanf("%d", &row);

	cnt = 1;
	for (int i = 1; i < row; i++)
	{
		cnt += union_cnt(row, i);
	}
	printf("%d\n", cnt);
}
int union_cnt(int n, int r)
{
	if (r == 0 || r == n)
		return 1;
	else {
		return union_cnt(n - 1, r - 1) + union_cnt(n - 1, r);
	}
}