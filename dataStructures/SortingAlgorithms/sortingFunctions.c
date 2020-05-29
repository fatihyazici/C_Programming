
#include "stdio.h"

void swapVal(int* a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*
*
*/
void selectionSort(int a[], int n) {
    for (int i = n-1; i >= 1; i--) {
        int maxIdx = i;
    for (int j = 0; j < i; j++)
        for (int j = 0; j < i; j++) 
            if (a[j] >= a[maxIdx])
                maxIdx = j;
    // swap routine is in STL <algorithm>
    swapVal(&a[i], &a[maxIdx]);
    }
}

/*
*
*/
void bubbleSort(int a[], int n) {
    for (int i = n-1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            for (int j = 1; j <= i; j++) {
                if (a[j-1] > a[j])
                    swapVal(&a[j], &a[j-1]);
                }
            }
    }
}

/*
*
*/
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int next = a[i];
        int j;
        for (j = i-1; j >= 0 && a[j] > next; j--)
            a[j+1] = a[j];

        a[j+1] = next;
    }    
}


int main()
{
    int arr[5] = {5,78,12,47,65};

    insertionSort(arr, 5);

    for(int i = 0 ; i<5;i++)
        printf("%d ", arr[i]);

    return 0;
}