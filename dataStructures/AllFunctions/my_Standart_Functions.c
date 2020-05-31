#include "stdio.h"
#include "string.h"




void swapFunc(int *value1, int *value2);
void swapFunc_2(int *value1, int *value2);

void print_TestPattern(int lastPoint);


int main()
{
    int a = 26;
    int b = 8;
    
    printf("before swap > a : %d , b : %d\n", a ,b);
    swapFunc_2(&a, &b);
    printf("after  swap > a : %d , b : %d\n", a ,b);


    print_TestPattern(10);

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