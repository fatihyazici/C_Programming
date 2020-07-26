#include "stdio.h"
#include "string.h"




void swapFunc(int *value1, int *value2);
void swapFunc_2(int *value1, int *value2);

void print_TestPattern(int lastPoint);
void print_TestPattern_Reverse(int lastPoint);


void selectionSort_1(int arr[], int size);


#define ARRAY_SIZE  10

int main()
{
    int a = 26;
    int b = 8;
    
    printf("before swap > a : %d , b : %d\n", a ,b);
    swapFunc_2(&a, &b);
    printf("after  swap > a : %d , b : %d\n", a ,b);

    int array[ARRAY_SIZE] = {12,22,543,8,67, 5, 1, 5432,12, 76}; 
 

 
    printf("ara1 : ");
    for(int i = 0 ; i< ARRAY_SIZE ; i++)
    {
        printf("%d " ,array[i]);
    }

    printf("\n");

    selectionSort_1(array , ARRAY_SIZE);

    printf("ara2 : ");
    for(int i = 0 ; i< ARRAY_SIZE ; i++)
    {
        printf("%d " ,array[i]);
    }

    return 0;
}



void swapFunc(int *value1, int *value2)
{
    int temp = 0;

    temp    = *value1;  // get value1's value to temp
    *value1 = *value2;  // get value2's value to value1
    *value2 =  temp;    // get temp's value to value2

    //printf("Val 1 : %d , Val 2 : %d\n", *value1 , *value2);
}


void swapFunc_2(int *value1, int *value2)
{
    /*for example *value1 : 7 , *value2 : 6*/
    *value1 = *value1 * *value2;    //*value1 = 7x6  = 42
    *value2 = *value1 / *value2;    //*value2 = 42/6 = 7;
    *value1 = *value1 / *value2;    //*value1 = 42/7 = 6

    //printf("Val 1 : %d , Val 2 : %d\n", *value1 , *value2);
}


/*
* print 1 to lastPoint pattern
* 1
* 1 2
* 1 2 3
* ...
* 1 2 3 4 5 ... n     
*/
void print_TestPattern(int lastPoint)
{
    for(int i = 1 ; i <= lastPoint ; i++)
    {
        for(int k = 1 ; k<=i ; k++)
        {
            printf("%d ", k);
        }

        printf("\n");
    
    }

}


void print_TestPattern_Reverse(int lastPoint)
{
    for(int i = 1 ; i <= lastPoint ; i++)
    {
        for(int k = lastPoint ; k>=i ; k--)
        {
            printf("%d ", k);
        }

        printf("\n");
    
    }

}



int fibonacci(int N) 
{
	int arr[2];
	
	arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= N; i++)
	   arr[i%2] = arr[0] + arr[1];

    return arr[N%2];
}



int fibonacci_recursive(int N){
    if(N == 0)          return 0;
    else if( N == 1)    return 1;
    else                return fibonacci_recursive(N-1) + fibonacci_recursive(N-2);   
    
}




//nice
void selectionSort_1(int arr[], int size)
{
    for(int i = size-1 ; i>=0 ;i--)
    {
        int maxIndx = i;
        for(int j = size-1; j>=i; j-- )
        {
            if(arr[maxIndx] > arr[j])
             {
                 maxIndx = j;
             }  

            swapFunc(&arr[maxIndx], &arr[i]);
        }
    }

}
