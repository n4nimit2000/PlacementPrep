#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vll vector<ll>

ll trapping_rainwater(vll &ar, ll n)
{
    ll ans = 0;
    ll left = 0, right = n - 1, left_max = 0, right_max = 0;

    while (left <= right)
    {
        if (ar[left] <= ar[right])
        {
            if (ar[left] >= left_max)
            {
                left_max = ar[left];
            }
            else
            {
                ans += (left_max - ar[left]);
            }
            left++;
        }
        else
        {
            if (ar[right] >= right_max)
            {
                right_max = ar[right];
            }
            else
            {
                ans += (right_max - ar[right]);
            }
            right--;
        }
    }

    return ans;
}

int main()
{
    ll n = 12;
    vll arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    ll ans = trapping_rainwater(arr, n);

    cout << ans;

    return 0;
}

/*
Given an array of N non-negative integers arr[] representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

Eg:
Input: arr = {0,1,0,2,1,0,1,3,2,1,2,1}
Output: ans = 6

*/