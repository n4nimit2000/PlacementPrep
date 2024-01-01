#include <iostream>
#include "template.h"

/**
 * Time Complexity = O(N), Space Complexity = O(1)
 **/
void reorderLinkedList(node *head)
{
    // Getting the middle node of the linked list
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reversing the second half of the linked list
    node *prev = NULL, *cur = slow->next;
    slow->next = NULL;
    while (cur != NULL)
    {
        node *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    // Merging the two linked lists by picking 1 node from each list
    node *head1 = head;
    node *head2 = prev;
    while (head2 != NULL)
    {
        node *tmp1 = head1->next;
        node *tmp2 = head2->next;
        head1->next = head2;
        head2->next = tmp1;
        head1 = tmp1;
        head2 = tmp2;
    }
}

/*
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Ref: https://leetcode.com/problems/reorder-list/description/
Solution: https://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/

*/