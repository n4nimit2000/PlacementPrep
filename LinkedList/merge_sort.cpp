#include <iostream>
#include "template.h"

using namespace std;

// write function code here
node *midpoint(node *head)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }

    node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node *merge(node *first_half, node *second_half)
{
    if (first_half == NULL)
        return second_half;
    if (second_half == NULL)
        return first_half;

    node *merged_list;
    if (first_half->data < second_half->data)
    {
        merged_list = first_half;
        merged_list->next = merge(first_half->next, second_half);
    }
    else
    {
        merged_list = second_half;
        merged_list->next = merge(first_half, second_half->next);
    }

    return merged_list;
}

node *merge_sort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *mid = midpoint(head);
    node *first_half = head;
    node *second_half = mid->next;
    mid->next = NULL;

    first_half = merge_sort(first_half);
    second_half = merge_sort(second_half);

    node *merged_list = merge(first_half, second_half);
    return merged_list;
}

int main()
{
    node *head = NULL;
    head = take_input();
    print(head);

    // call functions here
    head = merge_sort(head);
    print(head);

    clean_up_linked_list(head);
    print(head);

    return 0;
}

/*
Perform Merge Sort on Linked list
Time complexity = O(NlogN)
Space complexity = O(N)

Sample Input:
8 6 2 3 7 1 9 4 10 \

Sample Output:
Linked list: 10 -> 4 -> 9 -> 1 -> 7 -> 3 -> 2 -> 6 -> 8 ->
Linked list: 1 -> 2 -> 3 -> 4 -> 6 -> 7 -> 8 -> 9 -> 10 ->
Linked list:

*/