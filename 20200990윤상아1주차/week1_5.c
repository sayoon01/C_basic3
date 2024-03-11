/*
*  20200990 컴퓨터학과 윤상아 (문제해결기법 3분반)
*/
#include <stdio.h>

int countChar(char s[], char c);
int main(void)
{
	char str[20];
	char ch;
	int t;

	printf("Enter a String : ");
	scanf_s("%s", str,sizeof(str));

	printf("Enter a character : ");
	scanf_s("%c", &ch, sizeof(ch));

	t = countChar(str, ch);

	printf("'%c' is appeared %d times\n", ch,t);

	return 0;
}
int countChar(char s[], char c)
{
	int time = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			time++;
	}

	return time;
}
