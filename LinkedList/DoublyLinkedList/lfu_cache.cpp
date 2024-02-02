#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, value, freq;
    Node *next, *prev;

    Node(int k, int v, int f)
    {
        key = k;
        value = v;
        freq = f;
        next = NULL;
        prev = NULL;
    }
};

// Doubly Linked List (DLL)
class List
{
public:
    Node *head, *tail;
    int sz;

    List()
    {
        head = new Node(-1, -1, 0);
        tail = new Node(-1, -1, 0);
        head->next = tail;
        tail->prev = head;
        sz = 0;
    }

    void addNode(Node *new_node)
    {
        Node *tmp = head->next;
        new_node->next = tmp;
        new_node->prev = head;
        head->next = new_node;
        tmp->prev = new_node;
        sz++;
    }

    void removeNode(Node *&node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        sz--;
    }
};

class LFUCache
{
    int max_cap;
    int min_freq;
    unordered_map<int, Node *> key_node_mp;
    unordered_map<int, List *> freq_list_map;

public:
    LFUCache(int capacity)
    {
        max_cap = capacity;
        min_freq = 0;
    }

    void updateFreqMap(Node *node)
    {
        // remove the node from freq_list_map[node->freq] list
        int cur_freq = node->freq;
        freq_list_map[cur_freq]->removeNode(node);

        // Update min_freq if the node removed is from freq_list_map[min_freq] list and size of this list becomes 0
        if (node->freq == min_freq && freq_list_map[cur_freq]->sz == 0)
        {
            min_freq++;
        }

        // Add the node to the freq_list_map[node -> freq + 1]
        int updatedFreq = node->freq + 1;
        if (freq_list_map.find(updatedFreq) == freq_list_map.end())
        {
            freq_list_map[updatedFreq] = new List();
        }
        freq_list_map[updatedFreq]->addNode(node);

        // Increase node -> freq by 1
        node->freq = updatedFreq;
    }

    int get(int key)
    {
        if (key_node_mp.find(key) != key_node_mp.end())
        {
            // If the key is already present in the LFUCache, update the freq_list_map
            Node *node = key_node_mp[key];
            int val = node->value;
            updateFreqMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (key_node_mp.find(key) != key_node_mp.end())
        {
            // If the key is already present in LFUCache then:
            // 1. Update the value for that key
            // 2. Update the freq_list_map
            Node *node = key_node_mp[key];
            node->value = value;
            updateFreqMap(node);
        }
        else
        {
            if (key_node_mp.size() == max_cap)
            {
                // If the max_cap of the LFUCache is reached, remove the LFU key's LRU node. Also remove this node from key_node_mp
                Node *min_freq_lru = freq_list_map[min_freq]->tail->prev;
                key_node_mp.erase(min_freq_lru->key);
                freq_list_map[min_freq_lru->freq]->removeNode(min_freq_lru);
            }

            // Create a new node and add it to freq_list_map[1] and also update the key_node_map
            Node *new_node = new Node(key, value, 1);
            min_freq = 1;
            if (freq_list_map.find(min_freq) == freq_list_map.end())
            {
                freq_list_map[min_freq] = new List();
            }
            freq_list_map[min_freq]->addNode(new_node);
            key_node_mp[key] = new_node;
        }
    }
};

int main()
{
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(1) << "\n";
    lfu.put(3, 3);
    cout << lfu.get(2) << "\n";
    lfu.put(4, 4);
    cout << lfu.get(1) << "\n";
    cout << lfu.get(3) << "\n";
    cout << lfu.get(4) << "\n";

    return 0;
}

/*

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

- LFUCache(int capacity): Initializes the object with the capacity of the data structure.
- int get(int key): Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
- void put(int key, int value): Update the value of the key if present, or inserts the key if not already present.
When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

The functions get and put must each run in O(1) average time complexit

Ref: https://leetcode.com/problems/lfu-cache/description/

Video Tutorial: https://www.youtube.com/watch?v=0PSB9y8ehbk&ab_channel=takeUforward


*/