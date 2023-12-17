#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prevlink;
    struct Node *link;
} Node;
Node *create(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node *));
    newNode->data = data;
    newNode->link = NULL;
    newNode->prevlink = NULL;
    return newNode;
}

void insertatbeginning(Node **head, int data)
{
    Node *newNode = create(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->prevlink = newNode;
        newNode->link = *head;
        *head = newNode;
    }
}
void insertatintermediate(Node **head, int data, int position)
{
    Node *newNode = create(data);
    Node *current = *head;
    Node *prev = NULL;
    int count = 1;
    while (current != NULL)
    {
        if (count == position)
        {
            prev->link = newNode;
            newNode->prevlink = prev;
            newNode->link = current;
            break;
        }
        count++;
        prev = current;
        current = current->link;
    }
}
void insertatlast(Node **head, int data)
{
    Node *newNode = create(data);
    Node *current = *head;
    Node *prev = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        while (current != NULL)
        {
            prev = current;
            current = current->link;
        }
        prev->link = newNode;
        newNode->prevlink = prev;
    }
}
void deleteatbeginning(Node **head)
{
    Node *current = *head;
    *head = current->link;
    (*head)->prevlink = NULL;
    free(current);
}
void deleteatlast(Node **head)
{
    Node *current = *head;
    Node *prev = NULL;
    while (current->link != NULL)
    {

        prev = current;
        current = current->link;
    }
    prev->link = NULL;
    free(current);
}
void display(Node **head)
{
    Node *current = *head;
    while (current != NULL)
    {
        printf("%d ", current->data);

        current = current->link;
    }
}

void deleteatintermediate(Node **head, int position)
{
    Node *current = *head;
    Node *prev = NULL;
    int count = 1;
    while (current != NULL)
    {
        if (count == position)
        {
            (current->link)->prevlink = prev;
            prev->link = current->link;
            free(current);
            break;
        }
        prev = current;
        current = current->link;
        count++;
    }
}
void reverse(Node **head)
{
    Node *current = *head;
    Node *prev = NULL;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        current->prevlink = next;
        prev = current;
        current = next;
    }
    *head = prev;
}
int main()
{

    Node *head = NULL;
    int num;
    while (1)
    {
        printf("1)insert at beginning\n2)insert at intermediate\n3)insert at last\n4)delete at beginning\n5)delete at intermediate\n6)delete at last\n7)display\n8)reverse\n");

        scanf("%d", &num);
        switch (num)
        {
            int ele;
            int pos;
        case 1:
            printf("enter a number to insert at beginning");
            scanf("%d", &ele);
            insertatbeginning(&head, ele);
            break;
        case 2:
            printf("enter a number to insert at intermediate");
            scanf("%d", &ele);
            printf("enter a position to insert");
            scanf("%d", &pos);
            insertatintermediate(&head, ele, pos);
            break;
        case 3:
            printf("enter a number to insert at last");
            scanf("%d", &ele);

            insertatlast(&head, ele);
            break;
        case 4:
            deleteatbeginning(&head);
            break;
        case 5:

            printf("enter a position to delete");
            scanf("%d", &pos);
            deleteatintermediate(&head, pos);

            break;
        case 6:
            deleteatlast(&head);
            break;

        case 7:

            printf("\n");
            display(&head);
            printf("\n");
            break;
        case 8:
            reverse(&head);

            printf("\n");
            display(&head);
            printf("\n");
            break;
        default:
            printf("wrong number");
            break;
        }
    }

    return 0;
}