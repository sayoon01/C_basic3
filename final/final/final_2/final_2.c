#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int a[], int n);
int solution(int a[], int n)
{
	int diff;
	int i;

	if (n == 1)
		return 1;

	diff = a[1] - a[0];

	for (int i = 1; i < n - 1; i++)
	{
		if (diff != a[i + 1] - a[i])
			return 0;
	}
	return 1;
}
void pick(int n, int* bucket, int bucketSize, int k,int Na,int *A, int *Nb,int *B,int* seq,int *sum) // 주소를 전달하면 포인터로 받아야한다 !!!!
{
	int i, item, smallest, lastIndex;

	if (k == 0)
	{
		// B -> seq
		// B를 모두 seq에 복사

		for (i = 0; i < Nb; i++)
			seq[i] = B[i];
		for (i = 0; i < bucketSize; i++) {
			seq[bucket[i]] = A[i];
			// i = 0; A[0] -> B[bucket[0]]
			// i = 1; A[1] -> B[bucket[1]]
			// ...
			//      ; A[i] -> B[bucket[i]]  <- 바꾸는 거기 때문에 원복해야함 , 원복 대신 seq에 저장후 바꾸기
		}

		if (solution(seq, Nb) == 1) {
			int tmp = 0;
			for (i = 0; i < Nb; i++) {
				printf("%d ", seq[i]);
				tmp += seq[i];
			}

			printf("( ");
			for (i = 0; i < bucketSize; i++)
				printf("%d ", bucket[i]);
			printf(" )");
			printf("\n");

			// sum <- tmp 전달
			// sum[0] = tmp;
			*sum = tmp;
		}
		return;
	}

	lastIndex = bucketSize - k - 1;
	
	smallest = 0; // <- 순열

	for (item = smallest; item < n; item++)
	{
		int j = 0;
		int flag = 0;

		for (j = 0; j <= lastIndex; j++)
			if (bucket[j] == item)
			{
				flag = 1;
				break;
			}

		if (flag == 1)
			continue;
		// 중복 검사

		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1, Na, A, Nb, B, seq, sum);
	}

}
int main(void)
{
	int Na, Nb;
	int* A, * B;
	int* bucket, * seq;
	int sum = -1;

	scanf("%d", &Na);
	A = malloc(sizeof(int) * Na);
	bucket = malloc(sizeof(int) * Na);
	for (int i = 0; i < Na; i++)
		scanf("%d", &A[i]);
	
	scanf("%d", &Nb);
	B = malloc(sizeof(int) * Nb);
	seq = malloc(sizeof(int) * Nb);
	for (int i = 0; i < Nb; i++) 
		scanf("%d", &B[i]);

	pick(Nb, bucket, Na, Na, Na, A, Nb, B, seq, &sum); //&sum 이렇게 전달하면 메인에서 만든 변수 sum을 공유할 수 있다

	printf("Sum = %d", sum);

	free(A);
	free(B);
	free(bucket);
	free(seq);
	return 0;
}

void bubbleSort(int a[], int n)
{
	int i, j, tmp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}