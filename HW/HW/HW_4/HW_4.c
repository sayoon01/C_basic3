#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int totalCount = 0;

void pick(int* options, int numOptions, int* selected, int selectSize, int remainingSize, int targetSum) {
    int i, lastIndex, smallest, item;
    int currentSum = 0;

    lastIndex = selectSize - remainingSize - 1;

    for (i = 0; i <= lastIndex; i++) {
        currentSum += options[selected[i]];
    }

    if (targetSum == currentSum) {
        totalCount++;
        return;
    }

    if (currentSum > targetSum)
        return;

    if (k == bucketSize)
        smallest = 0;
    else
        smallest = selected[lastIndex] + 1;

    for (item = smallest; item < numOptions; item++) {
        selected[lastIndex + 1] = item;
        pick(options, numOptions, selected, selectSize, remainingSize - 1, targetSum);
    }
}

int main(void) {
    int numOptions;
    int options[] = { 1, 2 };

    scanf("%d", &numOptions);
    int* selected = (int*)malloc(sizeof(int) * numOptions);

    pick(options, 2, selected, numOptions, numOptions, numOptions);
    printf("%d\n", totalCount);

    free(selected);

    return 0;
}
