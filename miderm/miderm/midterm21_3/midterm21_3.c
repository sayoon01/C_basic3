// 사다리타기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j;
	int n, m;
	int start;
	char p[100][100];

	scanf("%d %d", &n, &m);
	scanf("%d", &start);

	for (i = 0; i < m; i++)
		scanf("%s", p[i]);
	
	j = 0;
	for(i=start;i<m;)
	{
		if (i == m - 1 && p[i][j] == '0')
		{
			printf("%d", j);
			break;
		}
		if (p[i][j] == '1')
			j++;
		else
			i++;
	}


}