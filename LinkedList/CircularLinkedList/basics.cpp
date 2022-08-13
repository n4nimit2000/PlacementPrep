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

void insert(node *&head, int data)
{
    node *new_node = new node(data);

    if (head == NULL)
    {
        new_node->next = new_node;
    }
    else
    {
        new_node->next = head;

        node *tmp = head;
        while (tmp->next != head)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }

    head = new_node;
}

void print(node *head)
{
    if (head == NULL)
    {
        cout << "Circular Linked List is empty!\n";
        return;
    }

    cout << "Cicular Linked List: ";
    node *tmp = head;
    while (tmp->next != head)
    {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << tmp->data << "\n";
}

node *take_input()
{
    int data;
    node *head = NULL;

    while (cin >> data)
    {
        insert(head, data);
    }

    return head;
}

node *get_node(node *head, int data)
{
    node *tmp = head;
    while (tmp->next != head)
    {
        if (tmp->data == data)
        {
            return tmp;
        }
        tmp = tmp->next;
    }

    if (tmp->data == data)
        return tmp;

    return NULL;
}

void delete_node(node *&head, int data)
{
    node *deleted_node = get_node(head, data);

    if (deleted_node == NULL)
        return;

    node *tmp = head;
    if (head == deleted_node)
    {
        if (head == head->next)
        {
            // Only 1 node exists
            head = NULL;
            delete (deleted_node);
            return;
        }
        head = head->next;
    }

    while (tmp->next != deleted_node)
    {
        tmp = tmp->next;
    }
    tmp->next = deleted_node->next;

    delete (deleted_node);
}

void clean_up_circular_linked_list(node *&head)
{
    while (head != NULL)
    {
        delete_node(head, head->data);
    }
}

int main()
{
    node *head = NULL;
    head = take_input();

    print(head);

    delete_node(head, 3);
    print(head);

    clean_up_circular_linked_list(head);
    print(head);

    return 0;
}

/*
Code for basic circular linked list operations

Sample Input:
8 6 2 3 7 1 9 4 10 \

Sample Output:
Cicular Linked List: 10 -> 4 -> 9 -> 1 -> 7 -> 3 -> 2 -> 6 -> 8
Cicular Linked List: 10 -> 4 -> 9 -> 1 -> 7 -> 2 -> 6 -> 8
Circular Linked List is empty!

*/