﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//#define MAX_LEVEL 5
//#define MAX_WIDTH 70
//int screen[MAX_LEVEL][MAX_WIDTH];
//int count = 0;
//
//void draw_tree(int row, int left, int right)  
//{
//    int mid;
//    if (right - left < 2) return;
//    mid = (right + left) / 2;
//
//    printf("**테스트 row=%d left=%d right=%d mid=%d\n", row, left, right, mid);
//    printf("  (%d %d)에 X를 찍는다\n", row, mid);
//
//    screen[row][mid] = ++count; 
//    draw_tree(row + 1, left, mid - 1); // 왼쪽 영역
//    draw_tree(row + 1, mid + 1, right); // 오른쪽 영역
//}
//
//void init(int s[][MAX_WIDTH])
//{
//    int i, j;
//    for (i = 0; i < MAX_LEVEL; i++)
//        for (j = 0; j < MAX_WIDTH; j++)
//            s[i][j] = 0;
//}
//
//void display(int s[][MAX_WIDTH], int width)
//{
//    int i, j;
//    for (i = 0; i < MAX_LEVEL; i++) {
//        for (j = 0; j < width; j++)
//        {
//            if (s[i][j] == 0)
//                printf(" -");
//            else
//                printf(" %d", s[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main(void)
//{
//    int width;
//
//    init(screen);
//
//    printf("Enter a width(<= 70) of a screen: ");
//    scanf("%d", &width);
//
//    draw_tree(0, 0, width - 1);
//    display(screen, width);
//}
#define MAX_LEVEL 5
#define MAX_WIDTH 70
char screen[MAX_LEVEL][MAX_WIDTH]; // 전역 변수 !!screen
int count = 0;

void draw_tree(int row, int left, int right)
{
    int mid;
    if (right - left < 2) return;
    mid = (right + left) / 2;

    printf("**테스트 row=%d left=%d right=%d mid=%d\n", row, left, right, mid);
    printf("  (%d %d)에 X를 찍는다\n", row, mid);

    screen[row][mid] = ++count; // int data 를 어떻게 형변환 없이 char[] 값에 저장 가능???????
    draw_tree(row + 1, left, mid - 1); // 왼쪽 영역
    draw_tree(row + 1, mid + 1, right); // 오른쪽 영역
}

void init(char s[][MAX_WIDTH])
{
    int i, j;
    for (i = 0; i < MAX_LEVEL; i++)
        for (j = 0; j < MAX_WIDTH; j++)
            s[i][j] = '-';
}

void display(char s[][MAX_WIDTH], int width)
{
    int i, j;
    for (i = 0; i < MAX_LEVEL; i++) {
        for (j = 0; j < width; j++)
        {
            if (s[i][j] == '-')
                printf(" %c", s[i][j]);
            else
                printf(" %d", s[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int width;

    init(screen);

    printf("Enter a width(<= 70) of a screen: ");
    scanf("%d", &width);

    draw_tree(0, 0, width - 1);
    display(screen, width);
}