#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id, kor, eng, mat;
};

void swap(struct Student* arr, int i, int j) {
	struct Student temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partitionId(struct Student* arr, int left, int right) {
	int pivot = arr[left].id;
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (low <= right && pivot >= arr[low].id)
			low++;
		while (high >= (left + 1) && pivot <= arr[high].id)
			high--;
		if (low <= high)
			swap(arr, low, high);
	}

	swap(arr, left, high);
	return high;
}

int partitionKor(struct Student* arr, int left, int right) {
	int pivot = arr[left].kor;
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (low <= right && pivot <= arr[low].kor)
			low++;
		while (high >= (left + 1) && pivot >= arr[high].kor)
			high--;
		if (low <= high)
			swap(arr, low, high);
	}

	swap(arr, left, high);
	return high;
}

int partitionMat(struct Student* arr, int left, int right) {
	int pivot = arr[left].mat;
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (low <= right && pivot <= arr[low].mat)
			low++;
		while (high >= (left + 1) && pivot >= arr[high].mat)
			high--;
		if (low <= high)
			swap(arr, low, high);
	}

	swap(arr, left, high);
	return high;
}

int partitionEng(struct Student* arr, int left, int right) {
	int pivot = arr[left].eng;
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (low <= right && pivot <= arr[low].eng)
			low++;
		while (high >= (left + 1) && pivot >= arr[high].eng)
			high--;
		if (low <= high)
			swap(arr, low, high);
	}

	swap(arr, left, high);
	return high;
}

void quick_sort(struct Student* arr, int left, int right, int choice) {
	int pivot;
	if (left <= right) {
		if (choice == 1)
			pivot = partitionKor(arr, left, right);
		else if (choice == 2)
			pivot = partitionMat(arr, left, right);
		else if (choice == 3)
			pivot = partitionEng(arr, left, right);
		else if (choice == 4)
			pivot = partitionId(arr, left, right);
		
		quick_sort(arr, left, pivot - 1, choice);
		quick_sort(arr, pivot + 1, right, choice);
	}
}

void printS(struct Student* s, int n) {
	for (int i = 0; i < n; i++) {
		printf("학번: %d\t", s[i].id);
		printf("국어: %d\t", s[i].kor);
		printf("수학: %d\t", s[i].mat);
		printf("영어: %d\n", s[i].eng);
	}
	printf("\n");
}

int main(void) {
	int n;
	printf("학생 수를 입력하세요: ");
	scanf("%d", &n);

	struct Student* s = (struct Student*)malloc(sizeof(struct Student) * n);
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		s[i].id = i + 1;
		s[i].kor = rand() % 101;
		s[i].eng = rand() % 101;
		s[i].mat = rand() % 101;
	}
	printS(s, n);

	int choice = -1;
	while (choice != 0) {
		printf("정렬 기준 선택<1: 국어, 2: 수학, 3: 영어, 4: id(오름차순), 0: 끝내기>: ");
		scanf("%d", &choice);

		if (choice == 1)
		{
			quick_sort(s, 0, n - 1, 1);
			printS(s, n);
		}
		else if (choice == 2)
		{
			quick_sort(s, 0, n - 1, 2);
			printS(s, n);
		}
		else if (choice == 3)
		{
			quick_sort(s, 0, n - 1, 3);
			printS(s, n);
		}
		else if(choice==4)
		{	quick_sort(s, 0, n - 1, 4);
		printS(s, n);
		}
	}
	free(s);

	return 0;
}