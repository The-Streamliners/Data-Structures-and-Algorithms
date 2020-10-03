#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void create(int n)
{
    struct Node *t, *last;
    int element;
    printf("enter data of 1 node");
    scanf("%d", &element);

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = element;
    first->next = NULL;
    last = first;

    for (int i = 2; i <= n; i++)
    {
        printf("enter data of %d node", i);
        scanf("%d", &element);
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = element;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct Node *p, int n)
{
    if (p == NULL)
    {
        printf("NUll LINKED LIST");
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}
void deletebegin(struct Node *p)
{
    struct Node *q = NULL;
    q = first;

    first = first->next;
    free(q);
}
void deleteend(struct Node *p, int n)
{
    struct Node *q = NULL;
    q = first;

    for (int i = 0; i < n - 1 && p; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
}
void delete (struct Node *p, int pos)
{
    struct Node *q = NULL;
    q = first;
    p = first;
    for (int i = 0; i < pos - 1 && p; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
}
int count(struct Node *p)
{
    int c=0;
    while (p != NULL)
    {
        p = p->next;
        c++;
    }
    return c;
}
int main()
{
    int choice, n, po, a;
    do
    {
        printf("\nenter your choice\nPress 1 to create\nPress 2 to display\nPress 3 to delete a node at beginning\nPress 4 to delete a node at end\nPress 5 to delete a node at any other position\nPress 6 to count total number of nodes\npress0 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter no. of nodes");
            scanf("%d", &n);
            create(n);
            break;
        case 2:
            display(first, n);
            break;

        case 3:
            deletebegin(first);
            n--;
            break;
        case 4:
            deleteend(first, n);
            n--;
            break;
        case 5:
            printf("Enter the position from which deletion is to be done");
            scanf("%d", &po);
            delete (first, po);
            n--;
            break;

        case 6:
            
            printf("number of nodes =%d", count(first));
            break;
        }
    } while (choice != 0);
}
