#include <bits/stdc++.h>
using namespace std;
 
/* Node structure */
struct Node {
    int data;
    struct Node* next;
};
 
void addNode(struct Node** head_ref, int new_data)
{
    struct Node* newnode = new Node;
    newnode->data = new_data;
    newnode->next = (*head_ref);
    *head_ref = newnode;
}
 
bool detectLoop(struct Node* head)
{
    unordered_set<Node*> s;
    while (head != NULL) {
        if (s.find(head) != s.end())
            return true;
        s.insert(head);
        head = head->next;
    }
    //not found
    return false;
}
 
void main()
{
    struct Node* head = NULL;
    addNode(&head, 20);
    addNode(&head, 4);
    addNode(&head, 15);
    addNode(&head, 10);
    head->next->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "Loop not found";
 
}
