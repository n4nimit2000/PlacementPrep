#include <iostream>
#include "template.h"

using namespace std;

// write function code here
void reverse_linked_list_iteratively(node *&head)
{
    node *cur = head;
    node *prev = NULL, *nxt = NULL;

    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
}

node *reverse_linked_list_recursively(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *rest = reverse_linked_list_recursively(head->next);
    head->next->next = head;

    head->next = NULL;
    return rest;
}

int main()
{
    node *head = NULL;
    head = take_input();
    print(head);

    // call functions here
    reverse_linked_list_iteratively(head);
    print(head);

    head = reverse_linked_list_recursively(head);
    print(head);

    clean_up_linked_list(head);
    print(head);

    return 0;
}

/*
Reverse the given linked list using both iteration and recursion.

Sample Input:
8 6 2 3 7 1 9 4 10 \

Sample Output:
Linked list: 10 -> 4 -> 9 -> 1 -> 7 -> 3 -> 2 -> 6 -> 8 ->
Linked list: 8 -> 6 -> 2 -> 3 -> 7 -> 1 -> 9 -> 4 -> 10 ->
Linked list: 10 -> 4 -> 9 -> 1 -> 7 -> 3 -> 2 -> 6 -> 8 ->
Linked list:

*/