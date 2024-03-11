#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void makeCode(char code[], int dist) {
    int i;

    for (i = 0; i < 26; i++) {
        code[i] = 'A' + ((i + dist) % 26);
    }
}

void printCode(char code[]) {
    int i;

    for (i = 0; i < 26; i++) {
        printf("%c", 'A' + i);
    }
    printf("\n");

    for (i = 0; i < 26; i++) {
        printf("%c", code[i]);
    }
    printf("\n");

}

void encode(char code[], char s[], char e[]) {
    int i = 0;

    for (i = 0; i < strlen(s); i++) {
        char ch = s[i];

        if ('A' <= ch && ch <= 'Z') {
            // encoding.
            int relative_pos = ch - 'A';
            e[i] = code[relative_pos];
        }
        //else if (ch == ' ') {
        //    // 공백 문자는 그대로 유지.
        //    e[i] = ' ';
        //}
        else {
           // printf("%d\n", ch); <- 내가 주석처리함
            e[i] = ch;
        }

    }
    e[i] = '\0'; //<- 내가 추가함
}

int main(void)
{
    char code[26]; // code[0]부터 ‘A’의 암호화문자를 넣음
    int distance;
    char sentence[80], encodedSentence[80];

    printf("Enter a distance for encoding:");
    scanf("%d", &distance);

    makeCode(code, distance);
    printCode(code);

   // fflush(stdin);
    gets(sentence);
    printf("Enter a sentence to encode:");
    gets(sentence);
    printf("original sentence:\t");
    puts(sentence);

    encode(code, sentence, encodedSentence);
    printf("encoded sentence:\t");
    puts(encodedSentence);
}