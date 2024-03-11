#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quick_selectionSort(int* A, int p, int r, int wNum);
int partition(int* A, int p, int r);
int main(void)
{
	int* list;
	int n, whichNum;

	printf("Enter the number of numbers : ");
	scanf("%d", &n);//몇개의 수를 받을 것인가?

	if (n <= 0) 	return 0;
	list = (int*)malloc(sizeof(int) * n);// n개 짜리 배열 만들기
	if (list == NULL) return 0;

	printf("몇번째로 작은 수 : ");
	scanf("%d", &whichNum);// 몇 번째 작은 수를 찾을 것인가?

	srand(time(NULL));//난수 발생기
	for (int i = 0; i < n; i++)
		list[i] = rand() % 100; // 100보다 작은 난수 n개 저장

	for (int i = 0; i < n; i++)
		printf("%d ", list[i]); // 난수 n개 출력
	printf("\n");

	int num = quick_selectionSort(list, 0, n - 1, whichNum); // whichNum번째 작은수
	printf("%d번째 작은 수는 %d\n", whichNum, num);
	
	free(list);
}
int quick_selectionSort(int* A, int p, int r, int wNum)
{
	int pivot;
	if (p < r) {
		pivot = partition(A, p, r);
		if (pivot == wNum - 1)
			return A[pivot];
		else if (pivot > wNum - 1)
			return quick_selectionSort(A, p, pivot - 1, wNum);
		else
			return quick_selectionSort(A, pivot + 1, r, wNum);
	}
	return A[p];
}
int partition(int* A, int p, int r)
{
	int i, j;
	int tmp;

	i = p - 1;
	for (j = p; j < r; j++) {
		if (A[j] < A[r]) {
			i++;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}

	i++;
	tmp = A[i];
	A[i] = A[r];
	A[r] = tmp;

	return i;
}