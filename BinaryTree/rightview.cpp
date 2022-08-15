#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

vector<int> right_view(node *root)
{
    vector<int> rightview;

    if (root == NULL)
        return rightview;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            node *cur = q.front();
            q.pop();

            if (i == n)
                rightview.push_back(cur->data);

            if (cur->left != NULL)
                q.push(cur->left);
            if (cur->right != NULL)
                q.push(cur->right);
        }
    }

    return rightview;
}