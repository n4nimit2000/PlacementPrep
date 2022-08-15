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

class Pair
{
public:
    ll branch_sum, max_sum;

    Pair()
    {
        branch_sum = 0;
        max_sum = 0;
    }
};

Pair max_sum_path(node *root)
{
    Pair res;

    if (root == NULL)
        return res;

    Pair lft = max_sum_path(root->left);
    Pair rgt = max_sum_path(root->right);

    ll op1 = root->data;
    ll op2 = lft.branch_sum + root->data;
    ll op3 = rgt.branch_sum + root->data;
    ll op4 = lft.branch_sum + rgt.branch_sum + root->data;

    ll cur_ans_through_root = max(op1, max(op2, max(op3, op4)));

    res.branch_sum = max(lft.branch_sum, max(rgt.branch_sum, 0 * 1LL)) + root->data;
    res.max_sum = max(lft.max_sum, max(rgt.max_sum, cur_ans_through_root));

    return res; // res.max_sum will contain the answer
}

/*
Maximum sum path from any node to another node (elements may be negative).
Time complexity = O(N)

*/