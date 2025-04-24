#include <bits/stdc++.h>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

void printTree(TreeNode* root) 
{
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) 
    {
        TreeNode* ptr = q.front();
        q.pop();
        if (ptr != nullptr) 
        {
            cout << ptr->val << ", ";
            q.push(ptr->left);
            q.push(ptr->right);
        }
    }
    cout << "\n";
}

TreeNode* newNode() 
{
    TreeNode* ptr = new TreeNode();
    ptr->val = -1;
    ptr->left = nullptr;
    ptr->right = nullptr;
    return ptr;
}

TreeNode* constructTree(vector<int>& arr) 
{
    if (arr.size() == 0) 
    {
        return nullptr;
    }
    queue<TreeNode*> treeNodeQueue;
    queue<int> integerQueue;
    int n = arr.size();
    for (int i = 1; i < n; i++) 
    {
        integerQueue.push(arr[i]);
    }
    TreeNode* root = newNode();
    root->val = arr[0];
    treeNodeQueue.push(root);
    while (!integerQueue.empty()) 
    {
        int lval = -1;
        if (!integerQueue.empty()) 
        {
            lval = integerQueue.front();
            integerQueue.pop();
        }
        int rval = -1;
        if (!integerQueue.empty()) 
        {
            rval = integerQueue.front();
            integerQueue.pop();
        }
        TreeNode* ptr = treeNodeQueue.front();
        treeNodeQueue.pop();
        if (lval != -1) 
        {
            TreeNode* left = newNode();
            left->val = lval;
            ptr->left = left;
            treeNodeQueue.push(left);
        }
        if (rval != -1) 
        {
            TreeNode* right = newNode();
            right->val = rval;
            ptr->right = right;
            treeNodeQueue.push(right);
        }
    }
    return root;
}

int main() 
{
    // for now, -1 represents -1 node, can change as needed
    vector<int> arr{3, 9, 20, -1, -1, 15, 7};
    TreeNode* root;
    root = constructTree(arr);
    printTree(root);
    return 0;
}