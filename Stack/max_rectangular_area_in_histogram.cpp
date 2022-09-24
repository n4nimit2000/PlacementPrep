#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

ll get_max_area(vll &ar)
{
    ll n = ar.size();
    ll ans = 0, ind = 0;
    stack<ll> st;

    while (ind < n)
    {
        while (st.size() && ar[st.top()] > ar[ind])
        {
            ll val = ar[st.top()];
            st.pop();

            ll cur = 0;
            if (st.empty())
            {
                cur = val * ind;
            }
            else
            {
                ll left = st.top();
                cur = val * (ind - left - 1);
            }
            ans = max(ans, cur);
        }
        st.push(ind);
        ind++;
    }

    while (st.size())
    {
        ll val = ar[st.top()];
        st.pop();

        ll cur = 0;
        if (st.empty())
        {
            cur = val * ind;
        }
        else
        {
            ll left = st.top();
            cur = val * (ind - left - 1);
        }
        ans = max(ans, cur);
    }

    return ans;
}

int main()
{
    vll histogram = {7, 2, 8, 9, 1, 3, 6, 5};

    ll max_area = get_max_area(histogram);
    cout << "Maximum rectangular area is " << max_area << "\n";

    return 0;
}

/*
Find the maximum rectangular area in a histogram.

Time Complexity = O(N)
Space Complexity = O(N)

Eg:
Input: histogram = {7,2,8,9,1,3,6,5}
Output: max_area = 16

*/