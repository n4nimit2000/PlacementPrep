#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

list<int> top_view(node *root)
{
    list<int> topview;

    if (root == NULL)
        return topview;

    queue<pair<node *, int>> q;
    q.push({root, 0});

    topview.push_back(root->data);

    int maxval = 0, minval = 0;

    while (q.size())
    {
        node *cur = q.front().first;
        int val = q.front().second;
        q.pop();

        if (val < minval)
        {
            minval = val;
            topview.push_front(cur->data);
        }

        if (val > maxval)
        {
            maxval = val;
            topview.push_back(cur->data);
        }

        if (cur->left)
            q.push({cur->left, val - 1});
        if (cur->right)
            q.push({cur->right, val + 1});
    }

    return topview;
}