#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define ipair pair<ll, ll>

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

ipair max_sum_helper(node *root)
{
    if (!root)
        return {0, 0};

    ipair left_sum = max_sum_helper(root->left);
    ipair right_sum = max_sum_helper(root->right);

    ipair cur_sum;

    cur_sum.first = root->data + left_sum.second + right_sum.second; // including the current node

    cur_sum.second = max(left_sum.first, left_sum.second) + max(right_sum.first, right_sum.second);

    return cur_sum;
}

ll max_sum_of_nodes(node *root)
{
    ipair max_sum = max_sum_helper(root);
    return max(max_sum.first, max_sum.second);
}

/*
Maximum sum of nodes in binary tree such that no two are adjacent.
Time complexity = O(N)

Solution:
Return a pair for each node in the binary tree such that the first of the pair indicates maximum sum when the
data of a node is included and the second indicates maximum sum when the data of a particular node is not
included.

*/