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

void print_at_level_k(node *root, ll k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    print_at_level_k(root->left, k - 1);
    print_at_level_k(root->right, k - 1);
}

// Code starts here
ll print_at_distance_k(node *root, node *target, ll k)
{
    if (!root)
        return -1;

    if (root == target)
    {
        print_at_level_k(target, k);
        return 1;
    }

    ll dl = print_at_distance_k(root->left, target, k);
    if (dl != -1)
    {
        if (dl == k)
            cout << root->data << " ";
        else
            print_at_level_k(root->right, k - 1 - dl);

        return dl + 1;
    }

    ll dr = print_at_distance_k(root->right, target, k);
    if (dr != -1)
    {
        if (dr == k)
            cout << root->data << " ";
        else
            print_at_level_k(root->left, k - 1 - dr);

        return dr + 1;
    }

    return -1;
}

/*
Print all nodes at a distance K from the given node.
Time Complexity = O(NK)

*/