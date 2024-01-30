#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, value;
    Node *next, *prev;

    Node(int k, int v)
    {
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};

class List
{
public:
    Node *head, *tail;

    List()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *node)
    {
        Node *tmp = head->next;
        node->next = tmp;
        head->next = node;
        node->prev = head;
        tmp->prev = node;
    }

    void removeNode(Node *&node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete (node);
    }
};

class LRUCache
{
    unordered_map<int, Node *> mp;
    List *dll = new List();
    int maxCapacity;

public:
    LRUCache(int capacity)
    {
        maxCapacity = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            int val = node->value;
            dll->removeNode(node);
            Node *new_node = new Node(key, val);
            dll->addNode(new_node);
            mp[key] = new_node;
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            dll->removeNode(node);
            mp.erase(key);
        }
        Node *new_node = new Node(key, value);
        dll->addNode(new_node);
        mp[key] = new_node;

        if (mp.size() > maxCapacity)
        {
            Node *last_node = dll->tail->prev;
            mp.erase(last_node->key);
            dll->removeNode(last_node);
        }
    }
};

int main()
{
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << "\n";
    lru.put(3, 3);
    cout << lru.get(2) << "\n";
    lru.put(4, 4);
    cout << lru.get(1) << "\n";
    cout << lru.get(3) << "\n";
    cout << lru.get(4) << "\n";
}

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

- LRUCache(int capacity): Initialize the LRU cache with positive size capacity.
- int get(int key): Return the value of the key if the key exists, otherwise return -1.
- void put(int key, int value): Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.


Ref: https://leetcode.com/problems/lru-cache

Video Tutorial: https://www.youtube.com/watch?v=xDEuM5qa0zg&ab_channel=takeUforward

*/