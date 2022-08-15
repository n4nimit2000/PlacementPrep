#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

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

node *last;

void convert(node *root, node *&head)
{
    if (root == NULL)
        return;

    convert(root->left, head);

    if (last == NULL)
    {
        head = root;
    }
    else
    {
        last->right = root;
        root->left = last;
    }

    last = root;

    convert(root->right, head);
}

node *binary_tree_to_dll(node *root)
{
    last = NULL;

    node *head = NULL;

    convert(root, head);

    return head;
}

/*
Convert the given binary tree to Doubly Linked List.
Time complexity = O(N)
Space complexity = O(H)


*/