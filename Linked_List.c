#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

    typedef struct node
{
    int data;          // stores the value of the node
    struct node *next; // pointer to the next node
} node;

node *init(int x)
{
    node *temp = (node *)malloc(sizeof(node)); // allocate memory for new node
    temp->data = x;                            // assign data
    temp->next = NULL;                         // next pointer set to NULL
    return temp;
}

void display(node *head)
{
    node *c = head; // pointer to traverse the list
    while (c)       // loop until NULL
    {
        printf("%d ", c->data);
        c = c->next;
    }
    printf("\n");
}

// Insert a node at the beginning of the list
node *insert_b(node *head, int x)
{
    node *temp = init(x);
    temp->next = head; // new node points to current head
    return temp;       // new node becomes the new head
}

// Insert a node at the end of the list
node *insert_l(node *head, int x)
{
    node *temp = init(x);
    node *c = head;

    while (c->next != NULL) // move to last node
    {
        c = c->next;
    }

    c->next = temp; // attach new node at end
    return head;    // head remains unchanged
}

// Insert a node at a specific position
node *insert_p(node *head, int x, int pos)
{
    node *c = head;
    node *temp = init(x);

    // move to node just before the desired position
    for (int i = 1; i <= pos - 2; i++)
    {
        c = c->next;
    }

    temp->next = c->next; // link new node to next node
    c->next = temp;       // link previous node to new node

    return head;
}

// Delete the first node of the list
node *delete_b(node *head)
{
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete the last node of the list
node *delete_l(node *head)
{
    node *c = head;

    // move to second last node
    while (c->next->next != NULL)
    {
        c = c->next;
    }

    node *temp = c->next;
    c->next = NULL;
    free(temp);

    return head;
}

// Delete a node at a specific position
node *delete_p(node *head, int pos)
{
    node *c = head;

    // move to node before the one to delete
    for (int i = 1; i <= pos - 2; i++)
    {
        c = c->next;
    }

    node *temp = c->next; // node to be deleted
    c->next = c->next->next;
    free(temp);

    return head;
}

int main()
{
    // create initial nodes
    node *head = init(10);
    node *f = init(20);
    node *s = init(30);
    node *t = init(40);

    // link nodes together
    head->next = f;
    f->next = s;
    s->next = t;

    display(head);

    printf("Insert at beginning : \n");

    head = insert_b(head, 99);
    display(head);

    printf("Insert at end : \n");
    head = insert_l(head, 999);
    display(head);

    printf("Insert at a specific position : \n");
    head = insert_p(head, 100, 4);
    display(head);

    printf("Delete from begining : \n");
    head = delete_b(head);
    display(head);

    printf("Delete from last : \n");
    head = delete_l(head);
    display(head);

    printf("Delete from a specific position : \n");
    head = delete_p(head, 3);
    display(head);
}
