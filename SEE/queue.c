#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};
// Structure to represent a queue
struct Queue
{
    struct Node *front;
    struct Node *rear;
};
// Function to initialize an empty queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}
// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue->front == NULL);
}
// Function to enqueue an element to the rear of the queue
void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
// Function to dequeue an element from the front of the queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue underflow: Cannot dequeue from an empty queue.\n");
        return -1; // Error value
    }
    struct Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}
// Function to display the elements of the queue
void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *current = queue->front;
    printf("Queue elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    struct Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);
    printf("Is the queue empty? %s\n", isEmpty(queue) ? "Yes" : "No");
    return 0;
}