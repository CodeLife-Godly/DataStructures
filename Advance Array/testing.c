#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high, int pivot) {
    int pivotIndex;
    // Find pivot index
    for (pivotIndex = low; pivotIndex <= high; ++pivotIndex) {
        if (arr[pivotIndex] == pivot) {
            break;
        }
    }
    
    // Move pivot to end
    swap(&arr[pivotIndex], &arr[high]);

    int i = low, j = low;
    while (j < high) {
        if (arr[j] < pivot) {
            swap(&arr[j], &arr[i]);
            ++i;
        }
        ++j;
    }
    swap(&arr[i], &arr[high]);

    return i;
}

int find_median(int* arr, int size) {
    qsort(arr, size, sizeof(int), compare);
    return arr[size / 2];
}

int medians_of_medians(int* arr, int low, int high) {
    int n = high - low + 1;

    if (n <= 5) {
        return find_median(arr + low, n);
    }

    int num_medians = (n + 4) / 5; // Corrected calculation
    int* medians = (int*)malloc(num_medians * sizeof(int));

    for (int i = 0; i < num_medians; ++i) {
        int start = low + i * 5;
        int end = start + 5;

        if (end > high + 1) {
            end = high + 1;
        }

        medians[i] = find_median(arr + start, end - start);
    }

    int mom = medians_of_medians(medians, 0, num_medians - 1);
    free(medians);
    return mom;
}

int k_th(int* arr, int low, int high, int k) {
    if (k < 1 || k > high - low + 1) {
        return -1;  // Invalid k
    }

    while (low <= high) {
        int pivot = medians_of_medians(arr, low, high);
        int pivotIndex = partition(arr, low, high, pivot);

        if (pivotIndex == low + k - 1) {
            return arr[pivotIndex];
        } else if (pivotIndex < low + k - 1) {
            low = pivotIndex + 1;
        } else {
            high = pivotIndex - 1;
        }
    }

    return -1;
}

int main() {
    int size, k;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    
    for (int i = 0; i < size; ++i) {
        printf("Enter: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int answer = k_th(arr, 0, size - 1, k);
    printf("%d\n", answer);

    free(arr);
    return 0;
}
