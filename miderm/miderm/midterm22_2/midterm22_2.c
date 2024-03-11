#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int item[3] = { -1,0,1 };

int makeSequence(int d, int n, int* p, int pSize, int toPick)
{

}
int main(void)
{
	int* p;
	float sum;
	int d0;
	int N;

	scanf("%d", &N);
	if (N <= 0)
	{
		printf("-1");
		return 0;
	}
	
	p = (int*)malloc(sizeof(int) * N);
	if (p == NULL) {
		printf("동적할당 실패\n");
		return -1;
	}

	for (int i = 0; i < N; i++)
		scanf("%d", &p[i]);

	d0 = 0;
	for (int i = 0; i < N - 1; i++)
		d0 += (p[i] - p[i + 1]);
	sum = sum / (N - 1);
	d0 = (int)(sum + 0.5);

	int count = makeSequence(d0, 3, p, N, N);
	if (count == 0)
		printf("-1");
	else
		printf("%d", count);
	free(p);
}