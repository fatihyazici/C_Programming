/*sadievrenseker_veriyapilari*/
/*sıralı ekleme*/

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
void addElementBetweenLinkedList(node *linkedList, int element , int place);

node* sortedInsert_LinkedList(node *tempRoot, int element);



int main()
{
    node *root;  //baslangıc
   
    root = NULL;

    root = sortedInsert_LinkedList(root, 12);
    root = sortedInsert_LinkedList(root, 15);
    root = sortedInsert_LinkedList(root, 29);
    root = sortedInsert_LinkedList(root, 24);
    root = sortedInsert_LinkedList(root, 27);

    print_LinkedList(root);
    
    
    return 0;
}


/*
*
*/
node* sortedInsert_LinkedList(node *tempRoot, int element)
{
    /*Liste boş ise alan aç ve elemanı oraya at*/
    if(tempRoot == NULL)
    {
        tempRoot = (node*)malloc(sizeof(node));

        tempRoot->next = NULL;
        
        tempRoot->data = element;

        return tempRoot;

    }

    /*ilk elemandan kucuk durumu , root değişiyor*/
    if(tempRoot->data > element)
    {
        node*temp = (node*)malloc(sizeof(node));

        temp->data = element;
    
        temp->next = tempRoot;

        return temp;

    }

    node *iter = tempRoot;
    while( (iter->next != NULL) && (iter->next->data < element)){
        iter = iter->next; 
    }

    node *temp = (node*) malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->data = element;


    return tempRoot;


}






/**/

void print_LinkedList(node *r)
{
    int count=0;


    while(r !=NULL)
    {
        printf("r[%d] %d\r\n", count, r->data);

        r = r->next;
        
        count++;
        if(count == 1000)
        {
            printf("Break Code''\r\n");
            break;
        }

    }

}