#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int medianOfThree(int a[], int low, int high) {
    int mid = (low + high) / 2;

    if (a[low] > a[mid]) swap(&a[low], &a[mid]);
    if (a[low] > a[high]) swap(&a[low], &a[high]);
    if (a[mid] > a[high]) swap(&a[mid], &a[high]);

    swap(&a[mid], &a[high - 1]);
    return a[high - 1];
}

int partition(int a[], int low, int high) {
    int pivot = medianOfThree(a, low, high);
    int i = low;
    int j = high - 1;

    for (;;){
        for (i = i + 1; i < high && a[i] < pivot; i++);

        for (j = j - 1; j > low && a[j] > pivot; j--);

        if (i < j)
            swap(&a[i], &a[j]);
        else
            break;
    }

    swap(&a[i], &a[high - 1]);
    return i;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        if (high - low + 1 <= 3) {
            for (int i = low + 1; i <= high; i++) {
                for (int j = i; j > low; j--) {
                    if (a[j] < a[j - 1]) {
                        int temp = a[j];
                        a[j] = a[j - 1];
                        a[j - 1] = temp;
                    } else break;
                }
            }
        } else {
            int pi = partition(a, low, high);
            quickSort(a, low, pi - 1);
            quickSort(a, pi + 1, high);
        }
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//Example usage for this question.
int main() {
    int arr[] = {10, -77, 90, -9, 1, 55};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The Ariginal Array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);
    printf("Median-of-three Quicksorted Array:  ");
    printArray(arr, n);

    system("pause");
    return 0;
}
