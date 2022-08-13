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

void insert_at_head(node *&head, int data)
{
    node *new_node = new node(data);
    new_node->next = head;
    if (head != NULL)
    {
        head->prev = new_node;
    }
    head = new_node;
}

int get_length(node *head)
{
    int length = 0;
    while (head != NULL)
    {
        head = head->next;
        length++;
    }
    return length;
}

void insert_at_tail(node *&head, int data)
{
    if (head == NULL)
    {
        insert_at_head(head, data);
        return;
    }

    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    node *new_node = new node(data);
    new_node->prev = tail;
    tail->next = new_node;
}

void insert_in_middle(node *&head, int data, int position)
{
    if (position <= 1 || head == NULL)
    {
        insert_at_head(head, data);
        return;
    }

    int length = get_length(head);
    if (length < position)
    {
        insert_at_tail(head, data);
        return;
    }

    node *tmp = head;
    for (int i = 1; i < position - 1; i++)
    {
        tmp = tmp->next;
    }

    node *new_node = new node(data);
    new_node->prev = tmp;
    new_node->next = tmp->next;
    tmp->next = new_node;

    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}

node *get_node(node *head, int data)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == data)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void delete_at_head(node *&head)
{
    if (head == NULL)
        return;

    node *tmp = head;
    head = head->next;

    if (head != NULL)
    {
        // when only 1 node is present
        head->prev = NULL;
    }

    delete tmp;
}

void delete_node(node *&head, int data)
{
    node *del = get_node(head, data);
    if (del == NULL)
    {
        return;
    }

    if (del == head)
    {
        delete_at_head(head);
        return;
    }

    node *before_del_node = del->prev;
    node *after_del_node = del->next;

    before_del_node->next = after_del_node;

    if (after_del_node != NULL)
    {
        after_del_node->prev = before_del_node;
    }

    delete del;
}

void take_input(node *&head)
{
    int data;
    while (cin >> data)
    {
        insert_at_head(head, data);
    }
}

void print(node *head)
{
    if (head == NULL)
    {
        cout << "Doubly Linked List in empty!\n";
        return;
    }

    cout << "Doubly Linked List: ";
    while (head->next != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << head->data << "\n";

    cout << "Reversed Linked List: ";
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->prev;
    }
    cout << "\n\n";
}

void clean_up_linked_list(node *&head)
{
    while (head != NULL)
    {
        delete_at_head(head);
    }
}

int main()
{
    node *head = NULL;
    take_input(head);
    print(head);

    delete_node(head, 1);
    print(head);

    clean_up_linked_list(head);
    print(head);

    return 0;
}

/*
Code for basic doubly linked list operations

Sample Input:
8 6 2 3 7 1 9 4 10 \

Sample Output:

*/