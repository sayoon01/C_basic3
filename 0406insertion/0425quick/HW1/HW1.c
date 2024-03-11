#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(struct Student* A, int p, int r);
int partitionByKorean(struct Student* A, int p, int r);
struct Student {
	int id;
	int english, math, korean;
};
int main(void)
{
	struct Student* A;
	int n;

	scanf("%d", &n);
	if (n <= 0)
		return 0;

	A = (struct Student*)malloc(sizeof(struct Student) * n);
	if (A == NULL)
		return 0;

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		A[i].id = i + 1;
		A[i].english = rand() % 101;
		A[i].math = rand() % 101;
		A[i].korean = rand() % 101;
	}

	printf("--정렬 전\n");
	for (int i = 0; i < n; i++)
		printf("학번 : %d	영어 : %d	수학 : %d	국어 : %d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	printf("\n");

	quickSort(A, 0, n - 1);
	printf("\n--국어 성적으로 정렬 후\n");
	for (int i = 0; i < n; i++)
		printf("학번 : %d	영어 : %d	수학 : %d	국어 : %d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	printf("\n");

	free(A);
}

void quickSort(struct Student* A, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partitionByKorean(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
int partitionByKorean(struct Student* A, int p, int r)
{
	int i = p - 1, j = p;
	struct Student tmp;

	while (j < r)
	{
		if (A[j].korean > A[r].korean)
		{
			i++;
			tmp = A[j];
			A[j] = A[i];
			A[i] = tmp;
		}
		j++;
	}

	i++;
	tmp = A[j];
	A[j] = A[i];
	A[i] = tmp;

	return i;
}