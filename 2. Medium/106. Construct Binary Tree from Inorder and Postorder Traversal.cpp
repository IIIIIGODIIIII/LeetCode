#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createBinaryTree(const vector<int>& values);
void printBinaryTree(TreeNode* root);
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
TreeNode* helper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inorderIdx, int inStart, int inEnd, int postIdx);

int main()
{
    vector<int> inorder = {9,3,15,20,7}, postorder = {9,15,7,20,3};
    TreeNode *root;

    root = buildTree(inorder, postorder);
    printBinaryTree(root);
    
    return 0;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    unordered_map<int, int> inorderIdx;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIdx[inorder[i]] = i;
        }
        return helper(inorder, postorder, inorderIdx, 0, inorder.size() - 1, postorder.size() - 1);
}

TreeNode* helper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inorderIdx, int inStart, int inEnd, int postIdx){
        if (inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postIdx]);
        int idx = inorderIdx[root->val];

        root->right = helper(inorder, postorder, inorderIdx, idx + 1, inEnd, postIdx - 1);
        root->left = helper(inorder, postorder, inorderIdx, inStart, idx - 1, postIdx - (inEnd - idx) - 1);

        return root;
}

// Helper Function to create a binary tree from a level-order input
TreeNode* createBinaryTree(const vector<int>& values){
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;
        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Helper Function to print the binary tree in level order
void printBinaryTree(TreeNode* root){
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (current) {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        } else {
            cout << "null ";
        }
    }
    
    cout << endl;
}