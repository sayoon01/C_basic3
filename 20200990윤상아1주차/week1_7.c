#include <stdio.h>

void echo(int a[])
{
	for (int i = 0; i < 5; i++)
		scanf_s("%d", &a[i]);
	printf("\n");
}
void echo(int a[])
{
	for (int i = 4; i >= 0; i--)
		printf("%d ", a[i]);
	printf("\n");
}
int main(void)
{
	int i;
	int array[5];

	echo(array);
	reverse(array);
}