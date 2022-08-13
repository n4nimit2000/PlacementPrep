#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next, *prev;

    node(int d)
    {
        data = d;
        next = NULL, prev = NULL;
    }
};

node *reverse_doubly_linked_list(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *cur = head, *tmp = NULL;
    while (cur != NULL)
    {
        // swap the 'next' and 'prev' pointers
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;

        cur = cur->prev;
    }

    head = tmp->prev;
    return head;
}

/*
Reverse the given DLL

*/