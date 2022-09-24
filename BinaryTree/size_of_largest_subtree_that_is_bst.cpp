#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf LLONG_MAX

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

class Info
{
public:
    ll sz;    // size of subtree
    ll mn;    // min value in subtree
    ll mx;    // max value in subtree
    ll ans;   // size of larget BST which is subtree of current node
    bool bst; // if current subtree in bst

    Info()
    {
        sz = 0;
        mx = -inf;
        mn = inf;
        ans = 0;
        bst = true;
    }
};

Info get_size_of_larget_bst(node *root)
{
    Info res;

    if (!root)
        return res;

    if (root->left == NULL && root->right == NULL)
    {
        res.sz = 1;
        res.mn = res.mx = root->data;
        res.ans = 1;
        res.bst = true;
        return res;
    }

    Info lft = get_size_of_larget_bst(root->left);
    Info rgt = get_size_of_larget_bst(root->right);

    res.sz = lft.sz + rgt.sz + 1;

    if (lft.bst && rgt.bst && lft.mx < root->data && rgt.mn > root->data)
    {
        res.mx = max(root->data, rgt.mx);
        res.mn = min(root->data, lft.mn);
        res.bst = true;
        res.ans = res.sz;
        return res;
    }

    res.ans = max(lft.ans, rgt.ans);
    res.bst = false;

    return res;
}

ll larget_bst(node *root)
{
    return get_size_of_larget_bst(root).ans;
}

/*
Given a Binary Tree, find the size of its larget subtree that is a BST.

Time Complexity = O(N)
Space Complexity = O(H)
*/