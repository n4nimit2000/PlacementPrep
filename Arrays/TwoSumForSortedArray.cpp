#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumForSortedArray(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    int start = 0, end = n - 1;
    while (start < end)
    {
        int sum = nums[start] + nums[end];
        if (sum == target)
        {
            ans.push_back(start);
            ans.push_back(end);
            break;
        }
        else if (sum < target)
        {
            start++;
        }
        else
        {
            end--;
        }
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

    vector<int> ans = twoSumForSortedArray(nums, target);
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

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.

Ref: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

*/
