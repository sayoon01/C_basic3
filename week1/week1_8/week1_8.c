#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(char n[]);
void reverse(char n[],int size);
int main(void)
{
	char name[81];
	int len;

	input(name);
	for (len = 0; name[len]; len++);
	reverse(name,len);
}

void input(char n[])
{
	printf("Enter your name : ");
	scanf("%s", n);
}

void reverse(char n[],int size)
{
	printf("Reverse : ");
	for (int i = 0; n[i] != '\0'; i++)
		printf("%c", n[size - 1 - i]);
	printf("\n");
}