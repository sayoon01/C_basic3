#include <stdio.h>
#include <string.h>

void inputArray(char s[])
{
	printf("Enter your Name : ");
	scanf_s("%s", s, sizeof(s));
}
void printReverseArray(char s[], int l)
{
	for (int i = l - 1; i >= 0; i--)
		printf("%c", s[i]);
	printf("\n");
}
int main(void)
{
	char str[100];
	int len;
	printf("Enter your name : ");
	inputArray(str);

	len = strlen(str);

	printReverseArray(str,len);

	return 0;
}