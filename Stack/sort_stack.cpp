#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

void insert_at_right_position(stack<ll> &st, ll tmp)
{
    if (st.empty())
    {
        st.push(tmp);
        return;
    }
    if (tmp > st.top())
    {
        st.push(tmp);
        return;
    }

    ll x = st.top();
    st.pop();
    insert_at_right_position(st, tmp);
    st.push(x);
}

void sort_stack(stack<ll> &st)
{
    if (!st.empty())
    {
        ll top_element = st.top();
        st.pop();
        sort_stack(st);
        insert_at_right_position(st, top_element);
    }
}

int main()
{
    vll ar = {1, 4, 2, 6, 2, 9, 2};
    stack<ll> st;

    for (auto element : ar)
    {
        st.push(element);
    }

    sort_stack(st);

    cout << "Sorted stack:\n";
    while (st.size())
    {
        cout << st.top() << "\n";
        st.pop();
    }

    return 0;
}


/*
Sort stack using recursion

Time complexity = O(N^2)
Space complexity = O(N)  // due to recursion
*/