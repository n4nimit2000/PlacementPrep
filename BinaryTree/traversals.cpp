#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

// Inorder Traversal
vector<int> inorder(node *root)
{
    vector<int> ar;
    stack<node *> st;
    node *cur = root;

    while (st.size() || cur != NULL)
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = st.top();
            ar.push_back(cur->data);
            st.pop();
            cur = cur->right;
        }
    }

    return ar;
}

// Preorder Traversal
vector<int> preorder(node *root)
{
    vector<int> ar;
    stack<node *> st;

    st.push(root);
    while (st.size())
    {
        node *cur = st.top();
        st.pop();

        ar.push_back(cur->data);

        if (cur->right)
            st.push(cur->right);
        if (cur->left)
            st.push(cur->left);
    }

    return ar;
}

// Postorder Traversal
vector<int> postorder(node *root)
{
    vector<int> ar;
    stack<node *> st;

    st.push(root);
    while (st.size())
    {
        node *cur = st.top();
        st.pop();

        ar.push_back(cur->data);

        if (cur->left)
            st.push(cur->left);
        if (cur->right)
            st.push(cur->right);
    }

    reverse(ar.begin(), ar.end());

    return ar;
}