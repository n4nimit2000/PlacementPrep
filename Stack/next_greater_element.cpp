#include <bits/stdc++.h>

using namespace std;

#define ll long long int

vector<ll> next_greater_element(vector<ll> arr)
{
    ll n = arr.size();
    vector<ll> ans(n, -1);
    stack<ll> st;

    for (ll i = 0; i < n; i++)
    {
        while (st.size() && arr[st.top()] < arr[i])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

int main()
{
    vector<ll> arr = {6, 8, 0, 1, 3};

    vector<ll> result = next_greater_element(arr);
    for (auto element : result)
    {
        cout << element << " ";
    }

    return 0;
}

/*
Given an vector arr[] of size N having distinct elements, find the next greater element for each element of the array
in order of their appearance in the array.

Eg:
Input: arr[] = {6,8,0,1,3}  N = 5
Output: {8, -1, 1, 3, -1}

Time Complexity = O(N)
Space Complexity = O(N)

*/