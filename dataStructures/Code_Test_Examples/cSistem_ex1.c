#include "stdio.h"




void bit_print_of_value(unsigned value)
{
    for (unsigned  i = 1 << 16; i > 0; i = i / 2) 
        (value & i)? printf("1"): printf("0");
}



void func(int x)
{
	++x;
	printf("%d ", x);
}
 
int main()
{
	int x = 3;
	int y = 5;
	int z = x + sizeof(++x) - sizeof(++y);
 
	printf("%d,%d,%d\n", x , y , z);
 
	return 0;
}