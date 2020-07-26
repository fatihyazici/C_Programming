#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/**/
unsigned int get_Strlen(const char *string)
{
    unsigned int length = 0;
    while(*string != '\0')
    {
        length++;
        string++;
    }

    return length;
}

void swap1(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}   


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
        swap1(&a[i], &a[minIdx]);
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sortedSquares(int* A, int ASize, int* returnSize){
    
    selectionSort(A, ASize);

    for(int i = 0; i<ASize ; i++)
    {
        //A[i] = (A[i]*A[i]);

       // printf("%d\n", A[i]);
    }    
    
 //   *returnSize = ASize;
    
    
    
  //  return A;
}



int main()
{


    return 0;
}