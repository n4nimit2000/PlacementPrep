#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next, *bottom;

    node(int d)
    {
        data = d;
        next = NULL, bottom = NULL;
    }
};

node *merge(node *l1, node *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    node *res = NULL;
    if (l1->data < l2->data)
    {
        res = l1;
        res->bottom = merge(l1->bottom, l2);
    }
    else
    {
        res = l2;
        res->bottom = merge(l1, l2->bottom);
    }

    return res;
}

// This is where the code starts
node *flattening_linked_list(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *tmp = flattening_linked_list(head->next);

    return merge(head, tmp);
}

/*
Link of the question - https://www.geeksforgeeks.org/flattening-a-linked-list/

Solution - Recursively merge the last two lists.
Time complexity = O(N*N*M)
Space complexity = O(N*M)

*/