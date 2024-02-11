#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    vector<Node *> links;

    Node()
    {
        links = vector<Node *>(2, NULL);
    }

    void put(int bit, Node *new_node)
    {
        links[bit] = new_node;
    }

    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }

    Node *getNext(int bit)
    {
        return links[bit];
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->getNext(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit))
            {
                maxNum |= (1 << i);
                node = node->getNext(1 - bit);
            }
            else
            {
                node = node->getNext(bit);
            }
        }

        return maxNum;
    }
};

int findMaximumXOR(vector<int> &nums)
{
    Trie trie;
    for (int &num : nums)
    {
        trie.insert(num);
    }

    int res = 0;
    for (int &num : nums)
    {
        res = max(res, trie.getMax(num));
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &num : nums)
        cin >> num;

    cout << findMaximumXOR(nums) << "\n";
}

/*

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Ref: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array

Time Complexity = O(N * 32)


Sample Input:
6
3 10 5 25 2 8

Sample Output:
28

*/