#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *Head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    //Linking head to first node
    Head->data = 12;
    Head->next = first;

    //Linking first to second node
    first->data = 11;
    first->next = second;

    //Linking second to third node
    second->data = 75;
    second->next = third;

    third->data = 78;
    third->next = NULL;

    display(Head);

    return 0;
}