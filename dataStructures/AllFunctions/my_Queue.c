/*Queue Functions*/
/*Fatih YAZICI*/

#include "stdio.h"
#include "stdlib.h"


#define INT_MIN     -2147483648


struct Queue{
    int front;
    int rear;

    int size;
    unsigned capacity;
    int *array;

};

typedef struct Queue _Queue;


_Queue* createQueue(unsigned capacity);
int isFull(_Queue *queue);
int isEmpty(_Queue *queue);
void enQueue(_Queue *queue, int item);
int deQueue(_Queue *queue);
int front(_Queue *queue);
int rear(_Queue *queue); 


int main()
{
    struct Queue* queue = createQueue(1000); 
  
    enQueue(queue, 10); 
    enQueue(queue, 20); 
    enQueue(queue, 30); 
    enQueue(queue, 40); 
  
    printf("%d dequeued from queue\n\n", deQueue(queue)); 
  
    printf("Front item is %d\n", front(queue)); 
    printf("Rear item is %d\n", rear(queue)); 

    return 0;
}




_Queue* createQueue(unsigned capacity)
{
    _Queue* queue = (_Queue*)malloc(sizeof(_Queue));

    queue->capacity = capacity;

    queue->size  = 0;
    queue->front = 0;
    queue->rear  = capacity-1;  //this is important  see the enqueue
    
    queue->array = (int*)malloc(sizeof(queue->capacity * sizeof(int)));

}


/****************************************************
* Queue is full when size becomes equal to the capacity  
*****************************************************/
int isFull(_Queue *queue)
{
    return (queue->size == queue->capacity);
}

/****************************************************
* Queue is empty when size is 0  
*****************************************************/
int isEmpty(_Queue *queue)
{
    return (queue->size == 0);
}


/****************************************************
* Function to add an item to the queue.   
* It changes rear and size
*****************************************************/
void enQueue(_Queue *queue, int item)
{
    if(isFull(queue))
        return;


    queue->rear = (queue->rear +1) % queue->capacity ; 

    queue->array[queue->rear] = item; 

    queue->size++;

    printf("%d enqueued to queue\n" , item);
}


int deQueue(_Queue *queue)
{
    if(isEmpty(queue))
        return INT_MIN;//INT_MIN


    int item = queue->array[queue->front];

    queue->front = (queue->front + 1 ) % queue->capacity;

    queue->size--;

    return item;
}

// Function to get front of queue 
int front(_Queue *queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
} 
  
// Function to get rear of queue 
int rear(_Queue *queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
}