#include <stdio.h>
#define SIZE 10



int main()
{
    int a[SIZE] = {2, 3, 1, 7, 9, 12, 4, 8, 19, 10};
    int i, k, min, index;
    
    for (k = 0; k < SIZE; ++k) 
    {
        min = a[k]; //min=2
        index = k;  //index=0
        for (i = k + 1; i < SIZE; ++i)
        {
            if (a[i] < min) 
            {
                min = a[i];
                index = i;
            }
        }
   
        a[index] = a[k];
        a[k] = min;  
              
    }

    for (k = 0; k < SIZE; ++k)
        printf("%d ", a[k]);
    
    
    return 0;
}