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
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void Insert(string &word)
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

    bool Search(string &word)
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

    void printAllWords()
    {
        string currentWord = "";
        cout << "[ ";
        DFS(root, currentWord);
        cout << "]\n";
    }

    void DFS(TrieNode *root, string &currentWord)
    {
        if (root->isWord == true)
            cout << currentWord << " ";

        for (int i = 0; i < root->children.size(); ++i)
        {
            char c = (char)(i + 'a');

            if (root->children[c - 'a'])
            {
                currentWord.push_back(c);
                DFS(root->children[c - 'a'], currentWord);
                currentWord.pop_back();
            }
        }
    }
};

int main()
{
    vector<string> words = {"look", "watch", "outer", "wish", "design", "watching", "install", "remove", "click", "inner"};
    vector<string> data = {"click", "cook", "lie", "remove", "home", "wish"};

    Trie *trie = new Trie();

    for (string &word : words)
        trie->Insert(word);

    trie->printAllWords();

    for (string &word : data)
        (trie->Search(word) == true) ? cout << word + " exists.\n" : cout << word + " doesn't exist.\n";
}