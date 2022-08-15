#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

ll get_right_boundary(ll low, ll high, vll &ar, ll key)
{
    ll right_boundary = low;
    while (low <= high)
    {
        ll mid = (low + high) >> 1;

        if (ar[mid] == key)
        {
            right_boundary = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return right_boundary;
}

ll get_left_boundary(ll low, ll high, vll &ar, ll key)
{
    ll left_boundary = high;
    while (low <= high)
    {
        ll mid = (low + high) >> 1;

        if (ar[mid] == key)
        {
            left_boundary = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return left_boundary;
}

ll get_element_with_odd_frequency(vll &ar, ll n)
{
    ll low = 0, high = n - 1;
    while (low <= high)
    {
        ll mid = (low + high) >> 1;

        ll left_boundary = get_left_boundary(0, mid, ar, ar[mid]);
        ll right_boundary = get_right_boundary(mid, n - 1, ar, ar[mid]);

        ll frequency = right_boundary - left_boundary + 1;

        if (frequency & 1)
        {
            return ar[mid];
        }

        if (left_boundary & 1)
        {
            // this means that the element with odd frequecy lies in the left half of the array
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}

void solve()
{
    ll n;
    cin >> n;

    vll ar(n);
    for (auto &x : ar)
    {
        cin >> x;
    }

    ll element_with_odd_frequency = get_element_with_odd_frequency(ar, n);

    cout << element_with_odd_frequency << "\n";
}

int main()
{
    ll testcases;
    cin >> testcases;

    while (testcases--)
    {
        solve();
    }
}

/*
Given a sorted array where exactly one value appears odd number of times and the rest of the values appear even times.
Find the element that appears odd number of times.

Time complexity = O(logN * logN)

Sample Input:
7
11
2 2 2 2 7 8 8 9 9 9 9
13
1 2 2 3 3 4 4 4 4 4 4 5 5
13
3 3 3 3 7 7 7 7 7 7 8 8 9
13
4 4 4 6 6 8 8 8 8 9 9 9 9
13
1 1 1 1 7 7 7 7 7 8 8 9 9
3
6 6 6
5
2 2 8 8 8

Sample Output:
7
1
9
4
7
6
8


*/