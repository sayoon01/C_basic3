//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//struct Student
//{
//	int id;
//	int korean, english, math;
//};
//
//void selectionSort(struct Student* A, int n);
//int main(void)
//{
//	struct Student* A;
//	int n;
//
//	scanf("%d", &n); // 학생의 수 입력
//	if (n <= 0)
//		return 0;
//
//	A = (struct Student*)malloc(sizeof(struct Student) * n);
//	if (A == NULL)
//		return 0;
//
//	srand(time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		A[i].id = i + 1;
//		A[i].korean = rand() % 101;
//		A[i].english = rand() % 101;
//		A[i].math = rand() % 101;
//	}
//	
//	printf("정렬전 --\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("학번 : %d  영어 : %d  수학 : %d  국어 : %d  \n", A[i].id, A[i].english, A[i].math, A[i].korean);
//	}
//	selectionSort(A, n);
//
//	printf("\n\n국어 성적 기준으로 정렬후 --\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("학번 : %d  영어 : %d  수학 : %d  국어 : %d  \n", A[i].id, A[i].english, A[i].math, A[i].korean);
//	}
//	free(A);
//}
//void selectionSort(struct Student* A, int n)
//{
//	struct Student tmp;
//	int i, j;
//	int min, min_idx;
//
//	for (i = 0; i < n - 1; i++)
//	{
//		min = A[0].korean;
//		min_idx = 0;
//
//		for (j = 1; j < n - i; j++)
//		{
//			if (A[j].korean < min)
//			{
//				min = A[j].korean;
//				min_idx = j;
//			}
//		}
//
//		tmp = A[min_idx];
//		A[min_idx] = A[n - 1 - i];
//		A[n - 1 - i] = tmp;
//	}
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student
{
	int id;
	int korean, english, math;
};
void selectionSort(struct Student* A, int n);
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
	for (int i = 0; i < n; i++)
	{
		A[i].id = i + 1;
		A[i].korean = rand() % 101;
		A[i].english = rand() % 101;
		A[i].math = rand() % 101;
	}
	printf("--정렬 전\n");
	for (int i = 0; i < n; i++)
	{
		printf("학번 : %d  영어 : %d  수학 : %d  국어 : %d  \n", A[i].id, A[i].english, A[i].math, A[i].korean);
	}

	selectionSort(A, n);
	printf("\n--정렬 후\n");
	for (int i = 0; i < n; i++)
	{
		printf("학번 : %d  영어 : %d  수학 : %d  국어 : %d  \n", A[i].id, A[i].english, A[i].math, A[i].korean);
	}

	free(A);
}
	void selectionSort(struct Student* A, int n)
	{
		int i, j;
		int min, min_idx;
		struct Student tmp;

		for (i = 0; i < n - 1; i++)
		{
			min = A[0].korean;
			min_idx = 0;
			for (j = 1; j < n - i; j++)
			{
				if (min > A[j].korean)
				{
					min = A[j].korean;
					min_idx = j;
				}
			}

			tmp = A[min_idx];
			A[min_idx] = A[n - 1 - i];
			A[n - 1 - i] = tmp;
		}
	}