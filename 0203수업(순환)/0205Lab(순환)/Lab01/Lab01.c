//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//void pick(int n, int picked[], int m, int toPick);
//int main(void)
//{
//    int picked[4]; 
//    pick(7, picked, 4, 4);
//    return 0; // main 함수의 반환값 추가
//}
//
//void pick(int n, int picked[], int m, int toPick)
//{
//    int i;
//    int lastIndex;
//    int smallest;
//
//    if (toPick == 0) {
//        for (i = 0; i < m; i++) {
//            printf("%d ", picked[i]);
//        }
//        printf("\n");
//        return;
//    }
//
//    lastIndex = m - toPick - 1;
//
//    if (m == toPick)
//        smallest = 0;
//    else
//        smallest = picked[lastIndex] + 1;
//
//    for (i = smallest; i < n; i++) {
//        picked[lastIndex + 1] = i;
//        pick(n, picked, m, toPick - 1);
//    }
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//void pick(int n, int picked[], int m, int toPick);
//int main(void)
//{
//    int picked[4];
//    pick(7, picked, 4, 4);
//    return 0; // main 함수의 반환값 추가
//}
//
//void pick(int n, int picked[], int m, int toPick)
//{
//    int i;
//    int lastIndex;
//    int big;
//
//    if (toPick == 0) {
//        for (i = 0; i < m; i++) {
//            printf("%d ", picked[i]);
//        }
//        printf("\n");
//        return;
//    }
//
//    lastIndex = m - toPick - 1;
//
//    if (m == toPick)
//        big = n;
//    else
//        big = picked[lastIndex] - 1;
//
//    for (i = big; i >=0; i--) {
//        picked[lastIndex + 1] = big;
//        pick(n, picked, m, toPick - 1);
//    }
//}