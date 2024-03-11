/*
*  20200990 컴퓨터학과 윤상아 (문제해결기법 3분반)
*/
#define SIZE 5
#include <stdio.h>

int searchIndex(int a[], int size, int searchKey);
int main(void)
{
	int num[SIZE];
	int index, key;

	printf("Enter %d개의 정수 : ",SIZE);
	for (int i = 0; i < SIZE; i++)
		scanf_s("%d", &num[i]);

	printf("Enter a key : ");
	scanf_s("%d", &key);

	index = searchIndex(num, SIZE, key);
	if (index == SIZE)
		printf("없다\n");
	else
		printf("%d번째에 있다\n", index);

	return 0;
}
int searchIndex(int a[], int size, int searchKey)
{
	for (int i = 0; i < size; i++)
		if (a[i] == searchKey)
			return i + 1;

	return size;
}

