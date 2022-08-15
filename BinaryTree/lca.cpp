#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

node *lca(node *root, int a, int b)
{
    if (!root)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    node *lft = lca(root->left, a, b);
    node *rgt = lca(root->right, a, b);

    if (lft != NULL && rgt != NULL)
        return root;

    if (lft != NULL)
        return lft;
    return rgt;
}