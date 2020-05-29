/*sadievrenseker_veriyapilari*/

#include <stdio.h>
#include <stdlib.h> //for malloc



/*structure*/
struct n{
    int data;
   struct  n * next;
};
typedef struct n node;

int main()
{
    node *root;  //baslangıc

    node *iter; // iterator , listede dolasmak için kullanılır.
    
    root = (node *)malloc(sizeof(node)); //bir tane node un hafızada kapladıgı kadar yeri ayırır.

    root->data = 10;
    root->next = (node * )malloc(sizeof(node));    //root'un next'inde de node kadar bir alan ac.

    root->next->data = 20;
    root->next->next = (node * )malloc(sizeof(node));    //root'un next'inde de node kadar bir alan ac.

    root->next->next->data = 30;    


    iter = root;

    printf("iter data1 : %d\r\n", iter->data);

    iter = iter->next;
    printf("iter data2 : %d\r\n", iter->data);
    
    
    for(int i = 1 ; i<=3;i++)
    {

    }



    return 0;
}

