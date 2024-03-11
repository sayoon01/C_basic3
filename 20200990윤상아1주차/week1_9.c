#include <stdio.h>

void inputArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
		scanf_s("%d", &a[i]);
}
int sameArray(int a1[], int a2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (a1[i] != a2[i])
			return 0;
	}
	return 1;
}
int main(void)
{
	int array1[5], array2[5];

	printf("Enter 첫번째 배열 : ");
	inputArray(array1, 5);
	printf("Enter 두번째 배열 : ");
	inputArray(array2, 5);
	
	if (sameArray(array1, array2, 5))
		printf("두 개의 배열은 같다\n");
	else
		printf("두 개의 배열은 다르다\n");

}