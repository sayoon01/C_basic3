#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student
{
	int id;
	int korean, english, math;
};

void printList(struct Student* A, int n)
{
	for (int i = 0; i < n; i++)
		printf("학번 : %d	영어 : %d	수학 : %d	국어 : %d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	printf("\n");
}

void quickSort(struct Student* A, int p, int r,int ask)
{
	if (p < r)
	{
		int q = partition(A, p, r,ask);
		quickSort(A, p, q - 1, ask);
		quickSort(A, q + 1, r, ask);
	}
}
int partition(struct Student* A, int p, int r, int ask)
{
	struct Student tmp;
	int i = p - 1, j;

	for(j=p;j<r;j++){
		if ((ask == 1 && A[j].korean > A[r].korean) || (ask == 2 && A[j].math > A[r].math) || (ask == 3 && A[j].english > A[r].english) || (ask == 4 && A[j].id < A[r].id)) {
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
int main(void)
{
	int n;
	int ask; // q는 원하는 기준
	struct Student * A;

	printf("학생 수를 입력하세요 : ");
	scanf("%d", &n);

	A = (struct Student*)malloc(sizeof(struct Student) * n);
	if (A == NULL)
		return 0;

	srand(time(NULL));
	for (int i = 0; i < n; i++){
		A[i].id = i + 1;
		A[i].korean = rand() % 101;
		A[i].english = rand() % 101;
		A[i].math = rand() % 101;
	}

	printList(A, n);

	printf("정렬 기준 선택(1:국어 2:수학 3:영어 4:id(오름차순) 0:끝내기) : ");
	scanf("%d", &ask);
	while (ask != 0){
		quickSort(A, 0, n - 1,ask);
		printList(A, n);
		printf("정렬 기준 선택(1:국어 2:수학 3:영어 4:id(오름차순) 0:끝내기) : ");
		scanf("%d", &ask);
	}
}