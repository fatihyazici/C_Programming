/*sadievrenseker_veriyapilari*/
/*Dairesel bağlı liste*/


#include <stdio.h>
#include <stdlib.h> //for malloc


/*structure*/
struct n{
    int data;
   struct  n * next;
};
typedef struct n node;


void print_CircledLinkedList(node *r);
void addToLinkedList(node * r , int x);
void addElementBetweenLinkedList(node *linkedList, int element , int place);

node* sortedInsert_LinkedList(node *tempRoot, int element);

node* deleteElementFrom_LinkedList(node* tempRoot, int element );

node* Reverse_LinkedList(node *head);


int main()
{
    node *root;  //baslangıc
   
    root = NULL;

    root = sortedInsert_LinkedList(root, 12);
    root = sortedInsert_LinkedList(root, 15);
    root = sortedInsert_LinkedList(root, 29);
    root = sortedInsert_LinkedList(root, 24);
    root = sortedInsert_LinkedList(root, 27);

    print_CircledLinkedList(root);

    root = deleteElementFrom_LinkedList(root, 24);

    
    print_CircledLinkedList(root);

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


node* deleteElementFrom_LinkedList(node* tempRoot, int element )
{
    node *temp;
    node *iter = tempRoot;

    //eger ilk eleman ise
    if(tempRoot->data == element)
    {
        temp = tempRoot;
        tempRoot = tempRoot->next;
        free(temp);

        return tempRoot;
    
    }
    //bir önceki elemana git
    while(iter->next != NULL && iter->next->data != element){
        iter = iter->next;
    }

    if(iter->next == NULL)
    {
         printf("There is No Element\r\n");
        return tempRoot;
    }   
        temp = iter->next;
        iter->next = iter->next->next;
        free(temp);

        return tempRoot;
}





/**/

void print_CircledLinkedList(node *r)
{
    int count=0;
    
    node *iter = r;

    printf("r[0] : %d" , iter->data);

    while(iter != r)
    {
        printf("r %d\r\n", r->data);

        iter = iter->next;
    
    }

}



node* Reverse_LinkedList(node *head)
{
 
    /****************************************************************************************
    *                                   a[0]          a[1]        a[2]        a[3]
    * 
    *                   ADDRESSES:     0x100         0x200       0x150       0x345
    Ex: NORMAL LIST   = head[0x100] > [5,0x200]  > [3,0x150] > [8,0x345] > [12,NULL] 
    -----------------------------------------------------------------------------------------
                         ADDRESSES:     0x345        0x150       0x200       0x100
        REVERSED LIST = head[0x345] > [12,0x150] > [8,0x200] > [3,0x100] > [5,NULL]    *
    *****************************************************************************************/

    node *prevNode , *nextNode ,  *currentNode; //set list

    currentNode = head; //currentnode initializes like first link (in ex: currentnode[0x100])

    prevNode = NULL;    //set null
   

    //as long as currentNode is not Last Node , slide 
    while(currentNode != NULL)
    {
        nextNode = currentNode->next;   //in first loop (now nextNode is a[1] = [3,0x150] )      , in second loop (now nextNode is a[2] = [8,0x345] )

        currentNode->next = prevNode;   //in first loop (now currentNode->next points to NULL)   , in second loop (now currentNode->next points to a[0] = [5,0x200] )

        prevNode = currentNode;         //in first loop (now prevNode is a[0] = [5,0x200] )      , in second loop (now prevNode is a[1] = [3, 0x150] )

        currentNode = nextNode;         //in first loop (now currentNode is a[1] = [3,0x150] )   , in second loop (now currentNode is a[2] = [8, 0x345] )

    }

    head = prevNode; //after currentNode is NULL > prevNode is a[3] , so head must be points to first byte and points to a[3] (prevNode)


    return head;
}


/*????????????????????????????*/
void Reverse_Recursion_LinkedList(node *r)
{

}