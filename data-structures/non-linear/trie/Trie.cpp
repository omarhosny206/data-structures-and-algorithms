#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char val;
    vector<TrieNode *> children;
    bool isWord;

    TrieNode()
    {
        this->children = vector<TrieNode *>(26);
        this->isWord = false;
    }

    TrieNode(char val)
    {
        this->val = val;
        this->children = vector<TrieNode *>(26);
        this->isWord = false;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            if (!current->children[c - 'a'])
                current->children[c - 'a'] = new TrieNode(c);

            current = current->children[c - 'a'];
        }

        current->isWord = true;
    }

    bool search(string &word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            if (!current->children[c - 'a'])
                return false;

            current = current->children[c - 'a'];
        }

        return current->isWord;
    }

    TrieNode *getStartNode(string &word)
    {
        TrieNode *current = root;

        for (char &c : word)
        {
            if (!current->children[c - 'a'])
                return nullptr;

            current = current->children[c - 'a'];
        }

        return current;
    }

    void dfs(TrieNode *root, string &currentWord)
    {
        if (root->isWord == true)
            cout << currentWord << " ";

        for (int i = 0; i < root->children.size(); ++i)
        {
            char c = (char)(i + 'a');

            if (root->children[c - 'a'])
            {
                currentWord.push_back(c);
                dfs(root->children[c - 'a'], currentWord);
                currentWord.pop_back();
            }
        }
    }

    void recommend(string prefix)
    {
        TrieNode *startNode = getStartNode(prefix);

        if (startNode == nullptr)
        {
            cout << "Cannot recommend" << endl;
            return;
        }

        string currentWord = prefix;
        cout << "recommendation for " + prefix + " [ ";
        dfs(startNode, currentWord);
        cout << "]\n";
    }

    void print()
    {
        string currentWord = "";
        cout << "[ ";
        dfs(root, currentWord);
        cout << "]\n";
    }
};

int main()
{
    vector<string> words = {"look", "watch", "outer", "wish", "design", "watching", "install", "remove", "click", "inner", "walking"};
    vector<string> data = {"click", "cook", "lie", "remove", "home", "wish"};

    Trie *trie = new Trie();

    for (string &word : words)
        trie->insert(word);

    trie->print();
    trie->recommend("wa");
    trie->recommend("wat");

    for (string &word : data)
        (trie->search(word) == true) ? cout << word + " exists.\n" : cout << word + " doesn't exist.\n";
}