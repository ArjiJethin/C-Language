#include <stdio.h>
#include <stdlib.h>
// Define a structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};
// Function to insert a node at the beginning of the list
struct Node *insertAtBeginning(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }
    newNode->data = value;
    newNode->next = head;
    return newNode;
}
// Function to insert a node at the end of the list
struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
// Function to delete a node by value
struct Node *deleteByValue(struct Node *head, int value)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return head;
    }
    if (head->data == value)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *current = head;
    while (current->next != NULL && current->next->data != value)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        printf("Value not found in the list. Cannot delete.\n");
        return head;
    }
    struct Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}
// Function to display the linked list
void displayList(struct Node *head)
{
    printf("Linked List: ");
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
    int choice, value;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete by value\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value to insert: ");
            scanf("%d", &value);
            head = insertAtBeginning(head, value);
            break;
        case 2:
            printf("Enter a value to insert: ");
            scanf("%d", &value);
            head = insertAtEnd(head, value);
            break;
        case 3:
            printf("Enter a value to delete: ");
            scanf("%d", &value);
            head = deleteByValue(head, value);
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            // Clean up and exit
            while (head != NULL)
            {
                struct Node *temp = head;
                head = head->next;
                free(temp);
            }
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}