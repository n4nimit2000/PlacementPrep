#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

class TreeNode
{
public:
    ll val;
    TreeNode *left, *right;

    TreeNode(ll d)
    {
        val = d;
        left = NULL;
        right = NULL;
    }
};

void getParents(TreeNode *cur, TreeNode *par, unordered_map<TreeNode *, TreeNode *> &mp)
{
    mp[cur] = par;
    if (!cur)
        return;

    getParents(cur->left, cur, mp);
    getParents(cur->right, cur, mp);
}

// Code starts here
void print_at_distance_k(TreeNode *root, TreeNode *target, ll k)
{
    // Get Parent nodes for each node in the tree
    unordered_map<TreeNode *, TreeNode *> par;
    getParents(root, NULL, par);

    // Traverse radially outwards from the target node
    unordered_map<TreeNode *, int> dis;
    queue<TreeNode *> q;
    q.push(target);
    dis[target] = 0;
    vector<int> ans;
    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();

        if (dis[cur] == k)
            ans.push_back(cur->val);

        if (cur->left && dis.find(cur->left) == dis.end())
        {
            dis[cur->left] = dis[cur] + 1;
            q.push(cur->left);
        }
        if (cur->right && dis.find(cur->right) == dis.end())
        {
            dis[cur->right] = dis[cur] + 1;
            q.push(cur->right);
        }
        if (par[cur] && dis.find(par[cur]) == dis.end())
        {
            dis[par[cur]] = dis[cur] + 1;
            q.push(par[cur]);
        }
    }

    for (auto node_at_distance_k : ans)
    {
        cout << node_at_distance_k << " ";
    }
}

/*
Print all nodes at a distance K from the given node.
Time Complexity = O(N)

Ref: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

Video Solution: https://www.youtube.com/watch?v=i9ORlEy6EsI&ab_channel=takeUforward

*/