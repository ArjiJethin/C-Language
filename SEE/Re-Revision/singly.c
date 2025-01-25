#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Error\n");
        return head;
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Error\n");
        return head;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
}

struct Node *deleteByValue(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if (head->data == key)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *current = head;
    while (current->next != NULL && current->next->data != key)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        printf("Element not found\n");
        return head;
    }
    struct Node *temp = current->next;
    current->next = current->next->next;
    free(temp);

    return head;
}

void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    head = insertAtBeginning(head, 7);
    head = insertAtBeginning(head, 5);
    head = insertAtEnd(head, 10);
    display(head);
    head = deleteByValue(head, 5);
    display(head);
    return 0;
}