#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>

/**
 * Time Complexity = O(N), Space Complexity = O(1)
 **/
bool canJump(vll &nums)
{
    int n = nums.size();
    if (n == 1)
        return true;
    ll cur_jump = nums[0];
    ll max_jump = nums[0];
    for (int i = 0; i < n - 1; i++)
    {
        max_jump = max(max_jump, i + nums[i]);
        if (cur_jump == i)
        {
            cur_jump = max_jump;
            if (cur_jump == i)
                return false;
        }
    }

    return true;
}

void solve()
{
    ll n;
    cin >> n;
    vll nums(n);
    for (auto &x : nums)
    {
        cin >> x;
    }

    if (canJump(nums))
        cout << "true\n";
    else
        cout << "false\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}

/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element
in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Sample Input:
2
5
2 3 1 1 4
5
3 2 1 0 4

Sample Output:
true
false

Ref: https://leetcode.com/problems/jump-game/

*/
