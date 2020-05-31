/*Stack Functions*/
/*Fatih YAZICI*/



#include "stdio.h"




/* Stack in ARRAYS*/
#define MAX_SIZE    101
int Array[MAX_SIZE];

int top_array = -1;

void Push_Array(int element);
void Pop_Array();
int Top_Array();
int isEmpty_Array();
void print_Stack_Array();


/* Stack in Linked Lists*/
struct Node{
    int data;
    struct Node* link;  
};

struct Node* top_linkedlist = NULL;

void Push_LinkedList(int element);
void Pop_LinkedList();


/*------------------------*/
int main()
{
    
    Push_Array(3);
    print_Stack_Array();


    struct Node* head;

    head = (struct Node*)malloc(sizeof(struct Node*));

    head = NULL;


    return 0;
}



void Push_Array(int element)
{
    if(top_array == MAX_SIZE -1)
    {
        printf("Error : Stack OverFlow!!\n");
        return;
    }

    Array[++top_array] = element;
}


void Pop_Array()
{
    if(top_array == -1 )
    {
        printf("Error : Stack is Empty\n");
        return;

    }

    top_array--;

}


int Top_Array()
{
    return Array[top_array];
}


int isEmpty_Array()
{
    if(top_array == -1)
        return 1;
    else
        return 0;
        
}


void print_Stack_Array()
{
    printf("Array Stack : ");

    for(int i= 0; i<=top_array ; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");

}


/*---------------------------------------*/

void Push_LinkedList(int element)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));

    temp->data = element;
    temp->link = top_linkedlist;

    top_linkedlist = temp;

}

void Pop_LinkedList()
{
    struct Node* temp;
    
    if(top_linkedlist == NULL)
        return;


    temp = top_linkedlist;
    top_linkedlist = top_linkedlist->link;
    free(temp);

}


void print_Stack_LinkedList()
{
    struct Node* iter = top_linkedlist;


}



void Reverse_String_Stack_Array(int *array ,  int arraySize)
{
    int temp = 0;
    int tempArray[MAX_SIZE] = {0};

    for(int i = 0 ; i< arraySize; i++)
    {
        Push_Array(array[i]);
    }

}