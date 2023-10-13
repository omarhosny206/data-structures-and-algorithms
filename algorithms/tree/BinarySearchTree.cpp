#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        left = right = nullptr;
    }

    TreeNode(int val)
    {
        this->val = val;
        left = right = nullptr;
    }

    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class BinarySearchTree
{
private:
    TreeNode *root;

    TreeNode *Insert(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);

        if (root->val > val)
            root->left = Insert(root->left, val);

        else
            root->right = Insert(root->right, val);

        return root;
    }

    TreeNode *Delete(TreeNode *root, int val)
    {
        if (root->val == val)
        {
            if (root->left == nullptr && root->right == nullptr)
                return nullptr;

            else if (root->left)
            {
                root->val = inOrderPredecessor(root->left);
                root->left = Delete(root->left, root->val);
            }

            else
            {
                root->val = inOrderSuccessor(root->right);
                root->right = Delete(root->right, root->val);
            }
        }

        else if (root->val > val)
            root->left = Delete(root->left, val);

        else
            root->right = Delete(root->right, val);

        return root;
    }

    int inOrderPredecessor(TreeNode *root)
    {
        while (root->right != nullptr)
            root = root->right;

        return root->val;
    }

    int inOrderSuccessor(TreeNode *root)
    {
        while (root->left != nullptr)
            root = root->left;

        return root->val;
    }

    bool Search(TreeNode *root, int target)
    {
        if (root == nullptr)
            return false;

        if (root->val == target)
            return true;

        if (root->val > target)
            return Search(root->left, target);

        return Search(root->right, target);
    }

    void getSortedNodes(TreeNode *root, vector<int> &sortedNodes)
    {
        if (root == nullptr)
            return;

        getSortedNodes(root->left, sortedNodes);
        sortedNodes.push_back(root->val);
        getSortedNodes(root->right, sortedNodes);
    }

    TreeNode *reConstructBST(TreeNode *root, vector<int> &sortedNodes, int start, int end)
    {
        if (start > end)
            return nullptr;

        int middle = start + (end - start) / 2;
        root = new TreeNode(sortedNodes[middle]);
        root->left = reConstructBST(root->left, sortedNodes, start, middle - 1);
        root->right = reConstructBST(root->right, sortedNodes, middle + 1, end);
        return root;
    }

    void preOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        cout << root->val << endl;
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        inOrder(root->left);
        cout << root->val << endl;
        inOrder(root->right);
    }

    void postOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << endl;
    }

    void levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int size = nodes.size();

            for (int i = 0; i < size; ++i)
            {
                TreeNode *current = nodes.front();
                nodes.pop();

                cout << current->val << " ";

                if (current->left != nullptr)
                    nodes.push(current->left);

                if (current->right != nullptr)
                    nodes.push(current->right);
            }

            cout << endl;
        }
    }

    void Construct(TreeNode *root, vector<vector<string>> &nodes, int level, int start, int end)
    {
        if (root == nullptr)
            return;

        int middle = start + (end - start) / 2;
        nodes[level][middle] = to_string(root->val);
        Construct(root->left, nodes, level + 1, start, middle - 1);
        Construct(root->right, nodes, level + 1, middle + 1, end);
    }

    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return 1 + max(left, right);
    }

public:
    BinarySearchTree(int val)
    {
        root = new TreeNode(val);
    }

    BinarySearchTree(vector<int> &nodes)
    {
        root = new TreeNode(nodes[0]);
        Print();
        cout << endl
             << endl;
        for (int i = 1; i < nodes.size(); ++i)
        {
            Insert(nodes[i]);
            Print();
            cout << endl
                 << endl;
        }
    }

    void Insert(int val)
    {
        if (Search(val) == false)
            Insert(root, val);

        getBalanced();
    }

    void Delete(int val)
    {
        if (Search(val) == true)
            Delete(root, val);

        getBalanced();
    }

    bool Search(int target)
    {
        return Search(root, target);
    }

    void getBalanced()
    {
        if (isBalanced() == true)
            return;

        vector<int> sortedNodes;
        getSortedNodes(root, sortedNodes);
        root = reConstructBST(root, sortedNodes, 0, sortedNodes.size() - 1);
    }

    bool isBalanced()
    {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return abs(leftHeight - rightHeight) <= 1;
    }

    void preOrder()
    {
        preOrder(root);
    }

    void inOrder()
    {
        inOrder(root);
    }

    void postOrder()
    {
        postOrder(root);
    }

    void levelOrder()
    {
        levelOrder(root);
    }

    void Print()
    {
        int height = getHeight();
        vector<vector<string>> nodes(height, vector<string>(pow(2, height) - 1, " "));
        Construct(root, nodes, 0, 0, nodes[0].size() - 1);

        for (vector<string> &level : nodes)
        {
            for (string &node : level)
                cout << node;

            cout << endl;
        }
    }

    int getHeight()
    {
        return getHeight(root);
    }
};

int main()
{
    BinarySearchTree *tree = new BinarySearchTree(100);
    tree->Insert(60);
    tree->Insert(50);
    tree->Insert(40);
    tree->Print();
    cout << endl
         << endl;
    tree->Insert(20);
    tree->Print();
    cout << endl
         << endl;
    tree->Insert(120);
    tree->Print();
    cout << endl
         << endl;
    tree->Insert(130);
    tree->Print();
    cout << endl
         << endl;
    tree->Insert(90);
    tree->Print();
    cout << endl
         << endl;
    tree->levelOrder();
    cout << endl
         << endl;
    tree->preOrder();
    cout << endl
         << endl;
    tree->postOrder();
    cout << endl
         << endl;
    tree->inOrder();
}