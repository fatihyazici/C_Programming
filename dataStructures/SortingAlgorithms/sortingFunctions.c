
#include "stdio.h"


/*
*
*/
void swapVal(int* a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    printf("swapped %d and %d \n", *a,*b);
}

/*
*  {5,78,12,47,65};
*/
void selectionSort(int a[], int n) {
    for (int i = 0 ; i < n-1; i++) 
    {
        int minIdx = i;
        
        for (int j = i ; j < n; j++) 
        {
           if (a[j] <= a[minIdx])
                minIdx = j;
        }

       // swap routine is in STL <algorithm>
        swapVal(&a[i], &a[minIdx]);
    }
}

/*
*
*/
void bubbleSort(int a[], int n) 
{
    for (int i = n-1; i >= 1; i--) 
    {
        for (int j = 1; j <= i; j++) 
        {
            if (a[j-1] > a[j])
                swapVal(&a[j], &a[j-1]);
        }
    }
}

/*
*
*/
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) 
    {
        int next = a[i];
        int j;
        for (j = i-1; j >= 0 && a[j] > next; j--)
            a[j+1] = a[j];

        a[j+1] = next;
    }    
}

/*
*
*/
int linearSearch(int arr[], int n , int searchElement )
{
    for(int i = 0 ; i < n ; i++)
    {
        if(searchElement == arr[i])
        {
            printf("%d.Element is %d \r\n", i ,searchElement );
            return i;
        }
    }

    printf("%d doesn't exist in List\n", searchElement);
    return -1;
}

/*
*
*/
int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}




int main()
{
    int arr[5] = {55,78,12,47,65};

    bubbleSort(arr, 5);
   


    int arr2[5] = {5,6,12,47,65};


    for(int i = 0 ; i<5;i++)
        printf("%d ", arr[i]);


    printf("Bin : %d\r\n", binarySearch(arr, 65 , 0 , 4) ) ;

    return 0;
}