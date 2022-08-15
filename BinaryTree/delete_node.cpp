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

node *delete_node(node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
            return NULL;
        else
            return root;
    }

    unordered_map<node *, node *> parent;
    queue<node *> q;
    q.push(root);

    node *key_node = NULL, *cur = NULL;
    char ch;

    while (q.size())
    {
        cur = q.front();
        q.pop();

        if (cur->data == key)
        {
            key_node = cur;
        }

        if (cur->left)
        {
            q.push(cur->left);
            parent[cur->left] = cur;
            ch = 'L';
        }
        if (cur->right)
        {
            q.push(cur->right);
            parent[cur->right] = cur;
            ch = 'R';
        }
    }

    if (key_node != NULL)
    {
        swap(cur->data, key_node->data);

        if (ch == 'R')
        {
            parent[cur]->right = NULL;
        }
        if (ch == 'L')
        {
            parent[cur]->left = NULL;
        }

        delete (cur);
    }

    return root;
}

/*
Given a binary tree of size N, write a code to delete a given node for the tree by making sure that tree shrinks
from the bottom (the deleted node is replaced by bottommost and rightmost node)

*/