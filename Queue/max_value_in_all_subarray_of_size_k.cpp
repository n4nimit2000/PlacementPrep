#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

vll get_max_value_of_all_subarrays_of_size_K(vll &ar, ll k)
{
    ll n = ar.size();

    deque<ll> q;
    vll max_values;

    for (ll i = 0; i < k; i++)
    {
        // remove the smaller elements from the rear end
        while (q.size() && ar[i] >= ar[q.back()])
        {
            q.pop_back();
        }

        // add current element at the rear end
        q.push_back(i);
    }

    for (ll i = k; i < n; i++)
    {
        max_values.push_back(ar[q.front()]);

        // remove elements that are not part of the current window
        while (q.size() && q.front() <= (i - k))
        {
            q.pop_front();
        }

        // remove the smaller elements from the rear end
        while (q.size() && ar[i] >= ar[q.back()])
        {
            q.pop_back();
        }

        // add current element at the rear end
        q.push_back(i);
    }

    max_values.push_back(ar[q.front()]);

    return max_values;
}

int main()
{
    vll ar = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    ll k = 4;

    vll max_values = get_max_value_of_all_subarrays_of_size_K(ar, k);

    cout << "Max values:\n";
    for (auto max_value : max_values)
    {
        cout << max_value << " ";
    }

    return 0;
}

/*
Given an array consisting of N non-negative integers and an integer K denoting the length of the subarray.
Find the maximum element in each subarray of size K.

Eg:
Input: ar = {8,5,10,7,9,4,15,12,90,13}, K = 4
Output: max_values = {10,10,10,15,15,90,90}

Time complexity = O(N)
Space complexity = O(K)

*/