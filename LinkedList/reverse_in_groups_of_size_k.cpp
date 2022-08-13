#include <bits/stdc++.h>
#include "template.h"

using namespace std;

node *reverse_in_groups_of_size_k(node *head, int k)
{
    node *cur = head, *tmp = NULL;
    while (cur != NULL)
    {
        node *prev = NULL, *nxt = cur, *last = cur;
        int kk = k;

        while (kk-- && cur != NULL)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        if (tmp != NULL)
            tmp->next = prev;
        else
            head = prev;

        tmp = last;
    }
    return head;
}

int main()
{
    int k;
    cin >> k;

    node *head = NULL;
    head = take_input();
    print(head);

    head = reverse_in_groups_of_size_k(head, k);
    print(head);

    clean_up_linked_list(head);
    print(head);

    return 0;
}

/*

Sample Input:
4
4 9 8 5 2 1 3 3 3 8 1 9 2 \

Sample Output:
Linked list: 2 -> 9 -> 1 -> 8 -> 3 -> 3 -> 3 -> 1 -> 2 -> 5 -> 8 -> 9 -> 4 ->
Linked list: 8 -> 1 -> 9 -> 2 -> 1 -> 3 -> 3 -> 3 -> 9 -> 8 -> 5 -> 2 -> 4 ->
Linked list:

*/