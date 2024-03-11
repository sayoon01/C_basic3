#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pick(int n, char s[],char picked[], int m,int toPick)
{
	int i, lastIndex = 0;
	int idx;

	if (toPick == 0)
	{
		for (i = 0; i < m; i++)
			printf("%c", picked[i]);
		printf("\n");
	}

	lastIndex = m - toPick - 1;
	if (m == toPick)
		idx = 0;
	else
		idx = lastIndex + 1;

	for (i = idx; i < m; i++)
	{
		picked[lastIndex + 1] = s[idx];
		pick(n, s, picked, m, toPick - 1);
	}
}
void arrageString(char s[])
{
	int i, j, minIndex, len;
	char tmp;

	for (len = 0; s[len] != '\0'; len++);
	for (i = 0; i < len - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < len; j++)
			if (s[j] < s[minIndex])
				minIndex = j;

		tmp = s[minIndex];
		s[minIndex] = s[i];
		s[i] = tmp;
	}
}
int main(void)
{
	char picked[81];
	char str[81];
	int n, m;

	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
		scanf("%c", &str[i]);

	arrageString(str);
	pick(n, str, picked, m, m);
}