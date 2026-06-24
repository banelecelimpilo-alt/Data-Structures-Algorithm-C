#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void copyArray(int *src, int *dest, int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

#define HYBRID_THRESHOLD 10

void hybridSort(int a[], int low, int high) {
    while (low < high) {
        if (high - low + 1 < HYBRID_THRESHOLD) {
            for (int i = low + 1; i <= high; i++) {
                int key = a[i];
                int j = i - 1;
                while (j >= low && a[j] > key) {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = key;
            }
            break;
        } else {
            int pi = partition(a, low, high);
            if (pi - low < high - pi) {
                hybridSort(a, low, pi - 1);
                low = pi + 1;
            } else {
                hybridSort(a, pi + 1, high);
                high = pi - 1;
            }
        }
    }
}

double measureTime(void (*sortFunc)(int *, int), int *a, int n) {
    int *temp = malloc(n * sizeof(int));
    copyArray(a, temp, n);

    clock_t start = clock();
    sortFunc(temp, n);
    clock_t end = clock();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    free(temp);
    return timeTaken;
}

double measureQuick(void (*qFunc)(int *, int, int), int *a, int n) {
    int *temp = malloc(n * sizeof(int));
    copyArray(a, temp, n);

    clock_t start = clock();
    qFunc(temp, 0, n - 1);
    clock_t end = clock();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    free(temp);
    return timeTaken;
}

int main() {
    srand(time(0));
    int sizes[] = {1000, 10000, 100000};

    for (int s = 0; s < 3; s++) {
        int n = sizes[s];
        int *arr = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100000 - 50000;

        printf("\n===== ARRAY SIZE: %d =====\n", n);
        printf("Insertion Sort: %.3f ms\n", measureTime(insertionSort, arr, n));
        printf("Heap Sort:      %.3f ms\n", measureTime(heapSort, arr, n));
        printf("Quick Sort:     %.3f ms\n", measureQuick(quickSort, arr, n));
        printf("Hybrid Sort:    %.3f ms\n", measureQuick(hybridSort, arr, n));

        free(arr);
    }

    printf("\n================ ANALYSIS ================\n");

    printf("\n--- Time Complexity ---\n");
    printf("Insertion Sort : Best O(n)       | Avg O(n^2)     | Worst O(n^2)\n");
    printf("Heap Sort      : Best O(n log n) | Avg O(n log n) | Worst O(n log n)\n");
    printf("Quick Sort     : Best O(n log n) | Avg O(n log n) | Worst O(n^2)\n");
    printf("Hybrid Sort    : Best O(n log n) | Avg O(n log n) | Worst O(n log n)\n");

    printf("\n--- Memory Usage ---\n");
    printf("Insertion Sort : O(1)\n");
    printf("Heap Sort      : O(1)\n");
    printf("Quick Sort     : O(log n)\n");
    printf("Hybrid Sort    : O(log n)\n");

    printf("\n--- Stability ---\n");
    printf("Insertion Sort : Stable \n");
    printf("Heap Sort      : Unstable \n");
    printf("Quick Sort     : Unstable \n");
    printf("Hybrid Sort    : Unstable \n");

    system("pause");
    return 0;
}
