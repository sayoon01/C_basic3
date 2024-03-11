#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//void echo(int a[])
//{
//	for (int i = 0; i < 5; i++)
//		scanf_s("%d", &a[i]);
//	printf("\n");
//}
//void echo(int a[])
//{
//	for (int i = 4; i >= 0; i--)
//		printf("%d ", a[i]);
//	printf("\n");
//}
void echo(int a[], int size);
void reverse(int a[], int size);
int main(void)
{
	int i;
	int array[5];

	echo(array,5);
	for (i = 0; i < 5; i++)
		printf("%d ", array[i]);
	printf("\n");
	reverse(array,5);
}

void echo(int a[], int size)
{
	for (int i = 0; i < size; i++)
		scanf("%d", &a[i]);
}

void reverse(int a[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", a[size - 1 - i]);
	printf("\n");
}