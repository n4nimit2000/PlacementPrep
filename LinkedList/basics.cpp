#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

int length_of_linked_list(node *head)
{
    int length = 0;
    node *tmp = head;

    while (tmp != NULL)
    {
        length++;
        tmp = tmp->next;
    }

    return length;
}

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

void insert_at_tail(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new node(data);
}

void insert_in_middle(node *&head, int data, int position)
{
    // corner case
    if (head == NULL || position == 0)
    {
        insert_at_head(head, data);
        return;
    }
    else if (position > length_of_linked_list(head))
    {
        insert_at_tail(head, data);
    }
    else
    {
        int jump = 1;
        node *tmp = head;
        while (jump < position - 1)
        {
            tmp = tmp->next;
            jump++;
        }

        node *new_node = new node(data);
        new_node->next = tmp->next;
        tmp->next = new_node;
    }
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

void delete_at_head(node *&head)
{
    if (head == NULL)
        return;

    node *tmp = head->next;
    delete (head);
    head = tmp;
}

void delete_in_middle(node *&head, int position)
{
    if (head == NULL)
        return;

    if (position == 0)
    {
        delete_at_head(head);
        return;
    }
    else if (position > length_of_linked_list(head))
    {
        return;
    }
    else
    {
        int jump = 1;
        node *node_before_deleted_node = head;
        while (jump <= position - 1)
        {
            node_before_deleted_node = node_before_deleted_node->next;
            jump++;
        }

        node *node_after_deleted_node = node_before_deleted_node->next->next;
        node *deleted_node = node_before_deleted_node->next;
        delete (deleted_node);
        node_before_deleted_node->next = node_after_deleted_node;
    }
}

void clean_up_the_linked_list(node *&head)
{
    while (head != NULL)
    {
        delete_at_head(head);
    }
}

int main()
{
    node *head = NULL;
    head = take_input();

    insert_at_head(head, 6);
    insert_in_middle(head, 2, 10);
    insert_at_tail(head, 15);

    print(head);

    delete_at_head(head);
    delete_in_middle(head, 3);

    print(head);

    clean_up_the_linked_list(head);
    print(head);

    return 0;
}

/*

Sample Input:
8 6 2 3 7 1 9 4 10 \

Sample Output:
Linked list: 6 -> 10 -> 4 -> 9 -> 1 -> 7 -> 3 -> 2 -> 6 -> 2 -> 8 -> 15 ->
Linked list: 10 -> 4 -> 9 -> 7 -> 3 -> 2 -> 6 -> 2 -> 8 -> 15 ->
Linked list:

*/