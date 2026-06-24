#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        for (int j = i; j > left; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
            } else {
                break;
            }
        }
    }
}

void heapify(int arr[], int n, int i, int start) {
    int largest = i;
    int left = 2 * (i - start) + 1 + start;
    int right = 2 * (i - start) + 2 + start;

    if (left < start + n && arr[left] > arr[largest])
        largest = left;
    if (right < start + n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, start);
    }
}

void heapSort(int arr[], int left, int right) {
    int n = right - left + 1;

    for (int i = left + n / 2 - 1; i >= left; i--)
        heapify(arr, n, i, left);

    for (int i = right; i > left; i--) {
        swap(&arr[left], &arr[i]);
        heapify(arr, i - left, left, left);
    }
}

int medianOfThree(int arr[], int a, int b, int c) {
    if (arr[a] < arr[b]) {
        if (arr[b] < arr[c]) return b;
        else if (arr[a] < arr[c]) return c;
        else return a;
    } else {
        if (arr[a] < arr[c]) return a;
        else if (arr[b] < arr[c]) return c;
        else return b;
    }
}

int partition(int arr[], int low, int high) {
    int m = medianOfThree(arr, low, (low + high) / 2, high);
    swap(&arr[m], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void introsortUtil(int arr[], int low, int high, int depthLimit) {
    int size = high - low + 1;

    if (size <= 16) {
        insertionSort(arr, low, high);
        return;
    }

    if (depthLimit == 0) {
        heapSort(arr, low, high);
        return;
    }


    int p = partition(arr, low, high);
    introsortUtil(arr, low, p - 1, depthLimit - 1);
    introsortUtil(arr, p + 1, high, depthLimit - 1);
}

void introsort(int arr[], int n) {
    int depthLimit = 2 * log(n);
    introsortUtil(arr, 0, n - 1, depthLimit);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage for this question.
int main() {
    int arr[] = {5,-201,31,-12,5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The Original Array: ");
    printArray(arr, n);

    introsort(arr, n);
    printf("Introsorted Hybrid Array: ");
    printArray(arr, n);

    system("pause");
    return 0;
}
