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

node *helper(vll &inorder, vll &preorder, ll start, ll end, unordered_map<ll, ll> &mp, ll &index)
{
    if (start > end)
        return NULL;

    ll cur = preorder[index++];
    node *new_node = new node(cur);

    ll inorder_index = mp[cur];
    new_node->left = helper(inorder, preorder, start, inorder_index - 1, mp, index);
    new_node->right = helper(inorder, preorder, inorder_index + 1, end, mp, index);
}

// Code starts here
node *construct_tree(vll &inorder, vll &preorder, ll n)
{
    ll index = 0;

    unordered_map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }

    node *root = helper(inorder, preorder, 0, n - 1, mp, index);

    return root;
}