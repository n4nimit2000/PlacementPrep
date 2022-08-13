#include <bits/stdc++.h>
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

class compare
{
public:
    bool operator()(node *p1, node *p2)
    {
        return p1->data > p2->data;
    }
};

node *sort_a_k_sorted_dll(node *head, int k)
{
    if (head == NULL)
        return head;

    priority_queue<node *, vector<node *>, compare> pq;

    node *new_head = NULL, *last;
    for (int i = 0; head != NULL && i <= k; i++)
    {
        pq.push(head);
        head = head->next;
    }

    while (pq.size())
    {
        if (new_head == NULL)
        {
            new_head = pq.top();
            new_head->prev = NULL;
            last = new_head;
        }
        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }

        pq.pop();

        if (head != NULL)
        {
            pq.push(head);
            head = head->next;
        }
    }

    last->next = NULL;

    return new_head;
}

/*
Given a DLL containing 'N' nodes, where each node is at most 'k' away from its target position in the list.
The problem is to sort the given linked list.
Time complexity = O(Nlogk)
Space complexity = O(k)


Sample Input:
k = 2
DLL = 3 6 2 12 56 8

Sample Output:
2 3 6 8 12 56

*/