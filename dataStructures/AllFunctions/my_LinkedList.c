
/* MY SINGLY LINKED LIST FUNCTIONS */
/*Fatih YAZICI*/


/*Each node 8 Bytes*/


#include <stdio.h>
#include <stdlib.h> //for malloc


/*structure*/
struct n{
    int data;
   struct  n * next;
};
typedef struct n node;



void print_LinkedList(node *r);
void print_LinkedList_Recursion(node *r);
void print_Reverse_LinkedList_Recursion(node *r);
void Print_CircledLinkedList(node *r);

void InsertTo_LinkedList(node * r , int x);
void InsertToPlace_LinkedList(node *head, int newElement , int place);
node* InsertTo_Sorted_LinkedList(node *head, int element);

node* DeleteFrom_LinkedList(node* head, int element );

node* Reverse_LinkedList(node *head);




int main()
{
    node *head;  //start

    head = (node *)malloc(sizeof(node)); //open place in memory for list (MUST !!)

    head->data = 10;    //first element
    head->next = NULL;  //(MUST !!)

    
    InsertTo_LinkedList(head, 25);

    head = DeleteFrom_LinkedList(head, 10);


    print_LinkedList(head);


    return 0;
}




/*-----------------------------------------------------------*/
/*                       FUNCTIONS                           */
/*-----------------------------------------------------------*/


/*******************************
* PRINT LINKED LIST FUNCTION
********************************/
void print_LinkedList(node *r)
{
    //print until r value is null
    while(r !=NULL)
    {
        printf("%d ", r->data);

        r = r->next;    //move to next link
    }
    printf("\n");
}

/**********************************************
* PRINT LINKED LIST FUNCTION (RECURSION METHOD)
**********************************************/
void print_LinkedList_Recursion(node *r)
{
    if(r == NULL)
    {
        printf("\n");
        return;

    }

    printf("%d ", r->data);
    print_LinkedList_Recursion(r->next);

}

/*******************************************************
* PRINT REVERSED LINKED LIST FUNCTION (RECURSION METHOD)
******************************************************/
void print_Reverse_LinkedList_Recursion(node *r)
{
    if(r == NULL)
    {
        printf("\n");
        return;
    }

    print_Reverse_LinkedList_Recursion(r->next);
    printf("%d ", r->data);
 
}


/***********************************
* PRINT CIRCLED LINKED LIST FUNCTION
***********************************/
void Print_CircledLinkedList(node *r)
{
    int count=0;
    
    node *iter = r;

    printf("%d " , iter->data);//print first element

    while(iter != r)
    {
        printf("%d ", r->data);

        iter = iter->next;
    
    }
    printf("\r\n");
}

/*******************************
* INSERT TO LINKED LIST FUNCTION
********************************/
void InsertTo_LinkedList(node * r , int x)
{
    while(r->next != NULL)
        r= r->next; //move to last element

    r->next = (node*) malloc(sizeof(node)) ; //open place for new element

    r->next->data = x;
    r->next->next = NULL;   //last character must be null

}


/*****************************************
* INSERT TO PLACE IN LINKED LIST FUNCTION
*****************************************/
void InsertToPlace_LinkedList(node *head, int newElement , int place)
{
    node *iter = head;

    for(int i = 0; i < place - 1 ;i++)
    {
        iter = iter->next;  //move to previous element
    }

    node *temp = (node *)malloc(sizeof(node));  //open place for new element

    temp->next = iter->next;    //then new element's next is previous's next .
    iter->next = temp;          //then previous's next is new element.

    temp->data = newElement;    //data is element

}

/*****************************************
* INSERT SORTED LINKED LIST FUNCTION
*****************************************/
node* InsertTo_Sorted_LinkedList(node *head, int element)
{
    /*list is empty open place for list and throw element there*/
    if(head == NULL)
    {
        head = (node*)malloc(sizeof(node)); //open place

        head->next = NULL; //must be null
        
        head->data = element;

        return head; //return list

    }

    /*if new element smaller then first element , replace root data */
    if(head->data > element)
    {
        node*temp = (node*)malloc(sizeof(node)); //open place for new data

        temp->data = element;   //throw element there
    
        temp->next = head; //then temp is root value, temp->next is r (r is second)

        return temp;    // return list

    }

    node *iter = head;
    //as long as new element bigger then list last data , iter moves to next.
    while( (iter->next != NULL) && (iter->next->data < element)){
        iter = iter->next; 
    }

    node *temp = (node*) malloc(sizeof(node)); //open place

    temp->next = iter->next;    //now temp last link
    iter->next = temp;          //iter->next point to last link(temp)
    temp->data = element;       //last data is biggest value : element

    return head;   //return list
}



/*****************************************
* Delete From LINKED LIST FUNCTION
*****************************************/
node* DeleteFrom_LinkedList(node* head, int element )
{
    node *temp;
    node *iter = head; //iter is root value

    //if element is first value
    if(head->data == element)
    {
        temp = head;    //temp is new root
        head = head->next; //root is next value   
        free(temp);  //delete first value

        return head;   //return list
    
    }
    //go to previous link
    while(iter->next != NULL && iter->next->data != element){
        iter = iter->next;
    }

    //if no element 
    if(iter->next == NULL)
    {
         printf("There is No Element\r\n");
        return head;   //return list
    }   
    
    temp = iter->next; //iter next assigned to temp value 
    iter->next = iter->next->next;  //then remove the element to be deleted
    free(temp); //delete element

    return head;   //return list
}



/********************************************
* REVERSE LINKED LIST FUNCTION with example
********************************************/
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


    return head;    //return reversed list
}



