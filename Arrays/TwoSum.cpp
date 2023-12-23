#include <bits/stdc++.h>
using namespace std;

// O(N) time complexity with O(N) space complexity
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];
        if (mp.find(diff) != mp.end())
        {
            ans.push_back(i);
            ans.push_back(mp[diff]);
            break;
        }
        mp[nums[i]] = i;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &x : nums)
    {
        cin >> x;
    }

    int target;
    cin >> target;

    vector<int> ans = twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << "\n";
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

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Ref: https://leetcode.com/problems/two-sum/description/

*/
