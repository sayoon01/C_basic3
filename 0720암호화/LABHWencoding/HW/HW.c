//#pragma warning(disable : 6031)
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void encode(char** code, char s[], char e[], int* key, int keySize) {
//    int i = 0;
//
//    for (i = 0; i < strlen(s); i++) {
//        char num = key[i % keySize];
//        e[i] = code[num - 'A'][s[i] - 'A'];
//    }
//    e[i] = '\0'; // 추가됨
//}
//
//int main(void)
//{
//    char** code;
//    //char code[26]; // code[0]부터 ‘A’의 암호화문자를 넣음
//    int key[4];
//    char sentence[80], encodedSentence[80];
//
//    for (int i = 0; i < 4; i++)
//        scanf("%d", &key[i]);
//
//    code = (char**)malloc(sizeof(char*) * 26);
//    for (int i = 0; i < 26; i++) {
//        code[i] = (char*)malloc(sizeof(char) * 26);
//        for (int j = 0; j < 26; j++) {
//            code[i][j] = 'A' + ((i + j + 1) % 26);
//        }
//    }
//
//    fflush(stdin);
//    gets(sentence);
//    printf("Enter a sentence to encode:");
//    gets(sentence);
//    printf("original sentence:\t");
//    puts(sentence);
//
//    encode(code, sentence, encodedSentence, key, 4);
//    printf("encoded sentence:\t");
//    puts(encodedSentence);
//
//    for (int i = 0; i < 26; i++) {
//        free(code[i]);
//    }
//    free(code);
//} 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void vigenereEncrypt(char* plaintext, char* keyword) {
    int plaintextLength = strlen(plaintext);
    int keywordLength = strlen(keyword);
    char ciphertext[MAX_LENGTH];

    for (int i = 0; i < plaintextLength; i++) {
        char currentChar = plaintext[i];
        char key = keyword[i % keywordLength];

        if (currentChar >= 'A' && currentChar <= 'Z') {
            currentChar = (currentChar - 'A' + key - 'A') % 26 + 'A';
        }
        else if (currentChar >= 'a' && currentChar <= 'z') {
            currentChar = (currentChar - 'a' + key - 'A') % 26 + 'a';
        }

        ciphertext[i] = currentChar;
    }

    ciphertext[plaintextLength] = '\0';
    printf("Encrypted message: %s\n", ciphertext);
}

void vigenereDecrypt(char* ciphertext, char* keyword) {
    int ciphertextLength = strlen(ciphertext);
    int keywordLength = strlen(keyword);
    char plaintext[MAX_LENGTH];

    for (int i = 0; i < ciphertextLength; i++) {
        char currentChar = ciphertext[i];
        char key = keyword[i % keywordLength];

        if (currentChar >= 'A' && currentChar <= 'Z') {
            currentChar = (currentChar - key + 26) % 26 + 'A';
        }
        else if (currentChar >= 'a' && currentChar <= 'z') {
            currentChar = (currentChar - key + 26) % 26 + 'a';
        }

        plaintext[i] = currentChar;
    }

    plaintext[ciphertextLength] = '\0';
    printf("Decrypted message: %s\n", plaintext);
}

int main() {
    char plaintext[MAX_LENGTH];
    char keyword[MAX_LENGTH];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    vigenereEncrypt(plaintext, keyword);
    vigenereDecrypt(plaintext, keyword);

    return 0;
}
