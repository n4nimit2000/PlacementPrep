#include <iostream>
#include "template.h"

using namespace std;

/**
 * Checks whether the given linked list contains a cycle or not.
 * Ref: https://leetcode.com/problems/linked-list-cycle/
 * Time Complexity = O(N), Space Complexity = O(1)
 **/
bool detectCycleInLinkedList(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

/**
 * Module to get the starting node of the linked list cycle.
 * Ref: https://leetcode.com/problems/linked-list-cycle-ii/submissions/
 * Time Complexity = O(N), Space Complexity = O(1)
 **/
node *getStartingPointOfLinkedListCycle(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}

/*
Ref: https://www.youtube.com/watch?v=2Kd0KKmmHFc&ab_channel=takeUforward

*/