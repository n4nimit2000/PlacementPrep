#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

void insert_at_bottom(stack<ll> &st, ll x)
{
    if (st.size() == 0)
    {
        st.push(x);
        return;
    }

    ll tmp = st.top();
    st.pop();
    insert_at_bottom(st, x);
    st.push(tmp);
}

void reverse(stack<ll> &st)
{
    if (st.size() == 0)
    {
        ll top_element = st.top();
        st.pop();
        reverse(st);
        insert_at_bottom(st, top_element);
    }
}

int main()
{
    vll ar = {4, 3, 2, 1};
    stack<ll> st;

    for (auto element : ar)
    {
        st.push(element);
    }

    reverse(st);
    cout << "\nReversed stack: \n";
    while (st.size())
    {
        cout << st.top() << "\n";
        st.pop();
    }
}

/*
Reverse a stack using recursion

Time Complexity = O(N^2)
Space Complexity = O(N)  // due to recursion

*/