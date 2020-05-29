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
void addToLinkedList(node * r , int x);



int main()
{

    node *root;  //baslangıc

    node *iter; // iterator , listede dolasmak için kullanılır.
    
    root = (node *)malloc(sizeof(node)); //bir tane node un hafızada kapladıgı kadar yeri ayırır.

    root->next = NULL; ///next her zaman null göstermeli

    root->data = 500;
 
    iter = root;

    printf("TEST\r\n");
    
    for(int i = 0; i<5; i++)
    {

        addToLinkedList(root ,i*10);
        
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
        
        if(count == 100)
        {
            printf("Break Code''\r\n");
            break;
        }

    }

}



void addToLinkedList(node * r , int x)
{
    while(r->next != NULL)
        r= r->next;

    r->next = (node*) malloc(sizeof(node)) ;

    r->next->data = x;
    r->next->next = NULL;

}