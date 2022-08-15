#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

void left_boundary_nodes(node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (root->left)
    {
        ans.push_back(root->data);
        left_boundary_nodes(root->left, ans);
    }
    else if (root->right)
    {
        ans.push_back(root->data);
        left_boundary_nodes(root->right, ans);
    }
}

void leaf_nodes(node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }

    leaf_nodes(root->left, ans);
    leaf_nodes(root->right, ans);
}

void right_boundary_nodes(node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (root->right)
    {
        right_boundary_nodes(root->right, ans);
        ans.push_back(root->data);
    }
    else if (root->left)
    {
        right_boundary_nodes(root->left, ans);
        ans.push_back(root->data);
    }
}

// Code starts here
void print_boundary(node *root)
{
    vector<int> ans;

    if (root)
    {
        cout << root->data << " ";

        left_boundary_nodes(root->left, ans);
        leaf_nodes(root, ans);
        right_boundary_nodes(root->right, ans);

        for (auto nodes : ans)
        {
            cout << nodes << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "-1\n";
    }
}