#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int is_in(char word[], char ch) {
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        if (word[i] == ch)
            return 1;
    }
    return 0;
}
void makeCode(char code[], char word[]) // 이 함수만 제출 
{
    int i,j; //idx
    int len;

    for (len = 0; word[len] != '\0'; len++);

    j = 0;
    for (i = 26 - len; i < 26; i++)
        code[i] = word[j++];

    i = 0, j = 0;
    while (i < 26 - len) {
        if (is_in(word, 'A' + j) == 0) {
            code[i] = 'A' + j;
            i++;
        }
        j++;
    }
    code[26] = '\0';
}

void printCode(char code[]) {
    int i;
    for (i = 0; i < 26; i++)
        printf("%c", code[i]);
}

int main(void) {
    char code[27];
    char keyWord[10];

    scanf("%s", keyWord);

    makeCode(code, keyWord);
    printCode(code);
}