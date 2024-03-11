#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* array, int left, int right) {
    int mid;
    int temp[10000];
    int l, m, tmp;

    mid = (left + right) / 2;
    l = left;
    m = mid + 1;
    tmp = left;

    while (l <= mid && m <= right) {
        if (array[l] <= array[m])
            temp[tmp++] = array[l++];
        else
            temp[tmp++] = array[m++];
    }

    if (l > mid) {
        while (m <= right)
            temp[tmp++] = array[m++];
    }
    else {
        while (l <= mid)
            temp[tmp++] = array[l++];
    }

    while (left <= right) {
        array[left] = temp[left];
        left++;
    }
}

void mergeSort(int* array, int left, int right) {
    int mid;

    if (left >= right)
        return;

    mid = (left + right) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, right);
}

void printList(int* A, int s, int e) {
    int i;
    for (i = s; i <= e; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(void) {
    int num;
    int* array;

    scanf("%d", &num);
    array = (int*)malloc(sizeof(int) * num);

    srand(time(NULL));
    for (int i = 0; i < num; i++)
        array[i] = rand() % 100001;

    mergeSort(array, 0, num - 1);
    printList(array, 0, num - 1);
    free(array);

    return 0;
}