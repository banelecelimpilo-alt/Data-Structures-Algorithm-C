#include <stdio.h>

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            } else {
                break;
            }
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
    int arr[] = {-22, 1, 19, 77, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The Original Array: ");
    printArray(arr, n);

    insertionSort(arr, n);
    printf("Insertion Sorted Array: ");
    printArray(arr, n);

    system("pause");
    return 0;
}
