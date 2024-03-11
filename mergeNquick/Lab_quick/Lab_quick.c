#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int array[], int p, int r) {
    int temp;
    temp = array[p];
    array[p] = array[r];
    array[r] = temp;
}

int partition(int array[], int left, int right) {
    int pivot;
    int low;
    int high;

    pivot = array[left];
    low = left + 1;
    high = right;

    while (low <= high) 
    {
        while (low <= right && pivot >= array[low])
            low++;
        while (high >= (left + 1) && pivot <= array[high])
            high--;
        if (low <= high)
            swap(array, low, high);
    }

    swap(array, left, high);
    return high;
}

void quickSort(int array[], int left, int right) {
    int pivot;
    if (left <= right) 
    {
        pivot = partition(array, left, right);
        quickSort(array, left, pivot - 1);
        quickSort(array, pivot + 1, right);
    }
}

void printList(int* A, int s, int e) {
    int i;
    for (i = s; i <= e; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    int num;
    int* array;

    scanf("%d", &num);
    array = (int*)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
        array[i] = rand() % 100001;

    quickSort(array, 0, num - 1);
    printList(array, 0, num - 1);
    free(array);

    return 0;
}