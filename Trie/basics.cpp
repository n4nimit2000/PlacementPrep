#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    vector<Node *> links;
    bool end;

    Node()
    {
        links = vector<Node *>(26, NULL);
        end = false;
    }

    void put(char ch, Node *new_node)
    {
        links[ch - 'a'] = new_node;
    }

    Node *getNext(char ch)
    {
        return links[ch - 'a'];
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void setEnd()
    {
        end = true;
    }

    bool isEnd()
    {
        return end;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    // Insert the word in Trie
    void insert(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->getNext(word[i]);
        }

        node->setEnd();
    }

    // Check if the word is present in Trie
    bool search(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->getNext(word[i]);
        }

        return node->isEnd();
    }

    // Check if there is any word in Trie with the given prefix
    bool startsWith(string prefix)
    {
        Node *node = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;

            node = node->getNext(prefix[i]);
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("appy");
    trie.insert("banana");
    trie.insert("mango");

    cout << "Is man present in Trie: " << trie.search("man") << "\n";
    cout << "Is apple present in Trie: " << trie.search("apple") << "\n";

    cout << "Does Trie contain the prefix app: " << trie.startsWith("app") << "\n";
    cout << "Does Trie contain the prefix apples: " << trie.startsWith("apples") << "\n";
    cout << "Does Trie contain the prefix bana: " << trie.startsWith("bana") << "\n";
}

/*
Sample Problems on Trie:
- https://leetcode.com/problems/implement-trie-prefix-tree/
- https://leetcode.com/problems/design-add-and-search-words-data-structure/
- https://leetcode.com/problems/word-search-ii/

Trie Video Tutorial - https://www.youtube.com/watch?v=dBGUmUQhjaM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&ab_channel=takeUforward
*/
