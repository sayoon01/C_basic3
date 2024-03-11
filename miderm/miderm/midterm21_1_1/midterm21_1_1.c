#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[])
{
	int i, len;
	for (i = 0; src_s[i] != '\0'; i++)
		s[i] = src_s[strlen(src_s) - 1 - i];
	s[i] = '\0';
}
int main(void)
{
	char src_s[101];
	char s[101];

	scanf("%s", src_s);
	reverse(src_s, s);
	printf("%s", s);
}