#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class node
{
public:
    ll data;
    node *left, *right;

    node(ll d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

ll count_pairs(node *root1, node *root2, ll x)
{
    if (!root1 || !root2)
        return 0;

    ll ans = 0;

    stack<node *> st1, st2;

    while (true)
    {
        while (root1)
        {
            st1.push(root1);
            root1 = root1->left;
        }
        while (root2)
        {
            st2.push(root2);
            root2 = root2->right;
        }

        if (st1.empty() || st2.empty())
            break;

        node *t1 = st1.top();
        node *t2 = st2.top();

        ll sum = t1->data + t2->data;

        if (sum == x)
        {
            ans++;
            st1.pop();
            st2.pop();

            root1 = t1->right;
            root2 = t2->left;
        }
        else if (sum < x)
        {
            st1.pop();
            root1 = t1->right;
        }
        else
        {
            st2.pop();
            root2 = t2->left;
        }
    }

    return ans;
}

/*
Count pairs from 2 BST whose sum is equal to given value x.

Time complexity = O(N)
Space complexity = O(H)

*/