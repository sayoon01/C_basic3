/*
*  20200990 컴퓨터학과 윤상아 (문제해결기법 3분반)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printNum(int a[], int size)
{
	printf("생성 번호 : ");
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
}
int main(void)
{
	int num[6];
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < 6; i++)
		num[i] = rand() % 46 + 1;

	printNum(num, 6);
	while (getchar() != '\0');



	return 0;
}