/*sadievrenseker_veriyapilari*/

#include <stdio.h>
#include <stdlib.h> //for malloc





/*structure*/
struct n{
    int data;
   struct  n * next;
};
typedef struct n node;


void print_LinkedList(node *r);


int main()
{
    node *root;  //baslangıc

    node *iter; // iterator , listede dolasmak için kullanılır.
    
    root = (node *)malloc(sizeof(node)); //bir tane node un hafızada kapladıgı kadar yeri ayırır.

    root->data = 500;
 
    iter = root;

    for(int i = 0; i<5; i++)
    {
        iter->next = (node * )malloc(sizeof(node));
        iter = iter->next;
        iter->data = i*5;
        iter->next = NULL;
    }

    print_LinkedList(root);

    return 0;
}



/**/

void print_LinkedList(node *r)
{
    int count=0;

    while(r !=NULL)
    {
        printf("r Data: %d\r\n", r->data);

        r = r->next;

    }

}

