/*sadievrenseker_veriyapilari*/
/*Baglı listede araya ekleme ve sıralı ekleme*/

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


void print_List_Recursion(node *p);
void print_ReverseList_Recursion(node *p);


int main()
{
    node *root;  //baslangıc
   
    root = (node *)malloc(sizeof(node)); //bir tane node un hafızada kapladıgı kadar yeri ayırır.

    root->next = NULL; ///next her zaman null göstermeli

    root->data = 500;
 
    for(int i = 0; i<3; i++)
    {
        addToLinkedList(root ,i*10);   
    }

    //print_LinkedList(root);

    node *iter = root; // iterator , listede dolasmak için kullanılır.
    
    //n kere next git o elemanı bul
    for(int i= 0 ;i<3;i++)
    {
        iter =iter->next;
    }

    //gecici degisken olustur 
    node *temp = (node*) malloc(sizeof(node));

    //araya ekledigin için iterin nextini artık sen göster , iterin nexti de seni göstersin
    temp->next = iter->next;
    iter->next = temp;

    temp->data = 100;

    //print_LinkedList(root);

    addElementBetweenLinkedList(root, 14 , 5);

    addElementBetweenLinkedList(root, 15 , 6);
    addElementBetweenLinkedList(root, 16 , 7);

    printf("--\r\n");
    print_LinkedList(root);

    printf("REC\r\n");

    print_List_Recursion(root);

    printf("REV REC\r\n");

    print_ReverseList_Recursion(root);

    return 0;
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



void addToLinkedList(node * r , int x)
{
    while(r->next != NULL)
        r= r->next;

    r->next = (node*) malloc(sizeof(node)) ;

    r->next->data = x;
    r->next->next = NULL;

}



void addElementBetweenLinkedList(node *linkedList, int element , int place)
{
    node *iter = linkedList;

    for(int i = 0; i<place-1;i++)
    {
        iter = iter->next;
    }

    node *temp = (node *)malloc(sizeof(node));

    temp->next = iter->next;
    iter->next = temp;

    temp->data = element;

}


void print_List_Recursion(node *p)
{
    if(p == NULL)
    {
        printf("\n");
        return;

    }

    printf("%d ", p->data);
    print_List_Recursion(p->next);

}


void print_ReverseList_Recursion(node *p)
{
    if(p == NULL)
    {
        printf("\n");
        return;

    }

    print_ReverseList_Recursion(p->next);
    printf("%d ", p->data);
 
}