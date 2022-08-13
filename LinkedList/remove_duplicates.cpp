#include <bits/stdc++.h>
#include "template.h"

using namespace std;

node *remove_duplicates(node *head)
{
    unordered_set<int> s;
    node *cur = head, *prev = NULL;
    while (cur != NULL)
    {
        int data = cur->data;
        node *last = cur;

        if (s.find(data) == s.end())
        {
            s.insert(data);
            cur = cur->next;
        }
        else
        {
            while (cur && s.find(cur->data) != s.end())
            {
                cur = cur->next;
            }
            prev->next = cur;
        }
        prev = last;
    }

    return head;
}

int main()
{
    node *head = NULL;
    head = take_input();
    print(head);

    head = remove_duplicates(head);
    print(head);

    clean_up_linked_list(head);
    print(head);

    return 0;
}

/*
Remove duplicate elements from an unsorted linked list

Sample Input:
4 9 8 5 2 1 3 3 3 8 1 9 2 \

Sample Output:
Linked list: 2 -> 9 -> 1 -> 8 -> 3 -> 3 -> 3 -> 1 -> 2 -> 5 -> 8 -> 9 -> 4 ->
Linked list: 2 -> 9 -> 1 -> 8 -> 3 -> 5 -> 4 ->
Linked list:

*/