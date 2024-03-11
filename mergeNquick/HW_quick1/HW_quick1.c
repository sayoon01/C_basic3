#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id, korea, english, math;
};

void swap(struct Student* arr, int i, int j) {
	struct Student temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(struct Student* arr, int left, int right) {
	int pivot = arr[left].korea;
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (low <= right && pivot <= arr[low].korea)
			low++;
		while (high >= (left + 1) && pivot >= arr[high].korea)
			high--;
		if (low <= high)
			swap(arr, low, high);
	}

	swap(arr, left, high);
	return high;
}

void quickSort(struct Student* arr, int left, int right) {
	if (left <= right) {
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}

void printS(struct Student* s, int n) {
	for (int i = 0; i < n; i++) {
		printf("학번: %d\t", s[i].id);
		printf("국어: %d\t", s[i].korea);
		printf("수학: %d\t", s[i].math);
		printf("영어: %d\n", s[i].english);
	}
	printf("\n");
}

int main(void) {
	int i;
	int n;
	struct Student* s;

	scanf("%d", &n);
	s = (struct Student*)malloc(sizeof(struct Student) * n);

	srand(time(NULL));

	for ( i = 0; i < n; i++) 
	{
		s[i].id = i + 1;
		s[i].korea = rand() % 101;
		s[i].english = rand() % 101;
		s[i].math = rand() % 101;
	}

	quickSort(s, 0, n - 1);
	printS(s, n);
	free(s);

	return 0;
}