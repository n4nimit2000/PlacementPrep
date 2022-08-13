#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insert_at_head(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *new_node = new node(data);
    new_node->next = head;
    head = new_node;
}

node *take_input()
{
    int data;
    node *head = NULL;
    while (cin >> data)
    {
        insert_at_head(head, data);
    }

    return head;
}

void delete_at_head(node *&head)
{
    if (head == NULL)
        return;

    node *tmp = head->next;
    delete (head);
    head = tmp;
}

void clean_up_linked_list(node *&head)
{
    while (head != NULL)
    {
        delete_at_head(head);
    }
}

void print(node *head)
{
    cout << "Linked list: ";
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "\n";
}

/*
Template code for Linked list problems.

Sample Input:
8 6 2 3 7 1 9 4 10 \

Sample Output:
Linked list: 10 -> 4 -> 9 -> 1 -> 7 -> 3 -> 2 -> 6 -> 8 -> 
Linked list:

*/