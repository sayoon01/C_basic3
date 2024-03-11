/*
*  20200990 컴퓨터학과 윤상아 (문제해결기법 3분반)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initNum(int a[], int size);
int main(void)
{
	int num[6];
	char choice;

	do
	{
		initNum(num, 6);
		printf("다시 생성하겠습니까?(y/n) ");
		scanf("%c", &choice);
		
		while (getchar() != '\n');
	} while (choice == 'y');



	return 0;
}


void initNum(int a[], int size)
{
	printf("\n*** 로또 번호 생성기 ***\n");
	printf("생성 번호 : ");
	for (int i = 0; i < size; i++) {
		a[i] = rand() % 44 + 1;
		printf("%d ", a[i]);
	}
	printf("\n");
}