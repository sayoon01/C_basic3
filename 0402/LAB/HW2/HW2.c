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
//void k_bubbleSort(struct Student* A, int n);
//void m_bubbleSort(struct Student* A, int n);
//void e_bubbleSort(struct Student* A, int n);
//void i_bubbleSort(struct Student* A, int n);
//int main(void)
//{
//	int key;
//	struct Student* A;
//	int n;
//
//	printf("학생 수를 입력하세요 : ");
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
//
//
//	do
//	{
//		printf("정렬 기준 선택 (1.국어, 2.수학, 3.영어, 4.id(오름차순) :, 0: 끝내기) ");
//		scanf("%d", &key);
//		if (key == 1)
//			k_bubbleSort(A, n);
//		else if (key == 2)
//			m_bubbleSort(A, n);
//		else if (key == 3)
//			e_bubbleSort(A, n);
//		else if (key == 4)
//			i_bubbleSort(A, n);
//		else if (key == 0)
//			break;
//
//		for (int i = 0; i < n; i++)
//		{
//			printf("학번 : %d  영어 : %d  수학 : %d  국어 : %d  \n", A[i].id, A[i].english, A[i].math, A[i].korean);
//		}
//
//	} while (key != 0);
//	
//	free(A);
//}
//
//void k_bubbleSort(struct Student* A,int n)
//{
//	struct Student tmp;
//	int i, j;
//
//	
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (A[j].korean > A[j + 1].korean)
//			{
//				tmp = A[j];
//				A[j] = A[j + 1];
//				A[j + 1] = tmp;
//			}
//
//		}
//	}
//}
//void m_bubbleSort(struct Student* A, int n)
//{
//	struct Student tmp;
//	int i, j;
//
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (A[j].math > A[j + 1].math)
//			{
//				tmp = A[j];
//				A[j] = A[j + 1];
//				A[j + 1] = tmp;
//			}
//		}
//	}
//}
//void e_bubbleSort(struct Student* A, int n)
//{
//	struct Student tmp;
//	int i, j;
//
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (A[j].english > A[j + 1].english)
//			{
//				tmp = A[j];
//				A[j] = A[j + 1];
//				A[j + 1] = tmp;
//			}
//		}
//	}
//}
//void i_bubbleSort(struct Student* A, int n)
//{
//	struct Student tmp;
//	int i, j;
//
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (A[j].id > A[j + 1].id)
//			{
//				tmp = A[j];
//				A[j] = A[j + 1];
//				A[j + 1] = tmp;
//			}
//		}
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
void bubbleSortDescendingByKorean(struct Student* A, int n);
void bubbleSortAscendingById(struct Student* A, int n);
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

	bubbleSortDescendingByKorean(A, n);
	printf("\n--국어 성적으로 정렬 후\n");
	for (int i = 0; i < n; i++)
	{
		printf("학번 : %d  영어 : %d  수학 : %d  국어 : %d  \n", A[i].id, A[i].english, A[i].math, A[i].korean);
	}

	bubbleSortAscendingById(A, n);
	printf("\n--학번 순으로 정렬 후\n");
	for (int i = 0; i < n; i++)
	{
		printf("학번 : %d  영어 : %d  수학 : %d  국어 : %d  \n", A[i].id, A[i].english, A[i].math, A[i].korean);
	}

	free(A);
}

void bubbleSortDescendingByKorean(struct Student* A, int n)
{
	struct Student tmp;
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (A[j].korean < A[j + 1].korean)
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}
}
void bubbleSortAscendingById(struct Student* A, int n)
{
	struct Student tmp;
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (A[j].id < A[j + 1].id)
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}
}