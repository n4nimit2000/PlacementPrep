#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next, *arb;

    node(int d)
    {
        data = d;
        next = NULL, arb = NULL;
    }
};

node *clone_a_linked_list(node *head)
{
    if (head == NULL)
        return NULL;

    node *tmp = head;
    while (tmp != NULL)
    {
        node *new_node = new node(tmp->data);
        new_node->next = tmp->next;
        tmp->next = new_node;
        tmp = tmp->next->next;
    }

    tmp = head;

    while (tmp != NULL)
    {
        if (tmp->arb != NULL)
        {
            tmp->next->arb = tmp->arb->next;
        }
        tmp = tmp->next->next;
    }

    tmp = head->next;
    node *copy = tmp;
    node *itr = head;

    while (itr != NULL)
    {
        itr->next = itr->next->next;
        if (tmp->next != NULL)
        {
            tmp->next = tmp->next->next;
        }

        tmp = tmp->next;
        itr = itr->next;
    }

    return copy;
}

/*
A linked list of length n is given such that each node contains an additional random ('arb') pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value
of its corresponding original node. Both the 'next' and 'arb' pointer of the new nodes should point to new nodes in the copied list such that the
pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

Time Complexity = O(N)
Space Complexity = O(1)

NOTE: This can also be easily done using hashmaps, but the space complexity will become O(N) in that case.

*/
