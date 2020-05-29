/* MY DOUBLY LINKED LIST FUNCTIONS */
/*Fatih YAZICI*/



/*reverse look up */
/*Each node 12 Bytes*/

#include <stdio.h>
#include <stdlib.h> //for malloc


/*structure*/
struct doubly_n{
    int data;
   struct  doubly_n * next;
   struct  doubly_n * prev;

};

typedef struct doubly_n doubly_node;


doubly_node *head;  //global variable - pointer to head node


void InsertAtHead_DoublyLinkedList( int element);
void InsertAtTail_DoublyLinkedList( int element);

void print_DoublyLinkedList();

void print_Reverse_DoublyLinkedList();

int main()
{

    head = NULL;

    InsertAtHead_DoublyLinkedList(2);   print_DoublyLinkedList();   //print_Reverse_DoublyLinkedList();

    InsertAtHead_DoublyLinkedList(4);   print_DoublyLinkedList();   //print_Reverse_DoublyLinkedList();

    InsertAtHead_DoublyLinkedList(6);   print_DoublyLinkedList();  //print_Reverse_DoublyLinkedList();

    InsertAtTail_DoublyLinkedList(7);   print_DoublyLinkedList();  //print_Reverse_DoublyLinkedList();

    InsertAtTail_DoublyLinkedList(8);   print_DoublyLinkedList();    print_Reverse_DoublyLinkedList();

    return 0;

}

/*
*
*/
doubly_node* GetNewNode_DoublyLinkedList(int element)
{
    doubly_node* newNode = (doubly_node*)malloc(sizeof(doubly_node));
    
    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    return newNode;

}


/*
*
*/
void InsertAtHead_DoublyLinkedList( int element)
{
    doubly_node* newNode = GetNewNode_DoublyLinkedList(element);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;

}


/*
*
*/
void InsertAtTail_DoublyLinkedList( int element)
{
    doubly_node* newNode = GetNewNode_DoublyLinkedList(element);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    doubly_node *iter = head;
    while(iter->next != NULL)
        iter = iter->next;

    iter->next = newNode;
    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = iter;

}



/*
*
*/
void print_DoublyLinkedList()
{

    doubly_node* temp = head;

    printf("Forward . ");

    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;

    }

    printf("\n");
}


/*
*
*/
void print_Reverse_DoublyLinkedList()
{

    doubly_node *temp = head;

    if(temp == NULL)    
        return;
    
    //going to last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }


    //Traversing backward using prev pointer
    printf("Reverse : ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}


