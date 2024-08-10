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
int maxPathSum(TreeNode* root);
int dfs(TreeNode* root, vector<int>&);

int main() {
    vector<int> list = {1, 2, 3};
    TreeNode* root = createBinaryTree(list);
    int maxSum = maxPathSum(root);
    cout << maxSum << endl;

    return 0;
}

int maxPathSum(TreeNode* root){
    vector<int> res = {root->val};
    dfs(root, res);
    return res[0];
}

int dfs(TreeNode* root, vector<int>& res) {
    if (root == nullptr) 
        return 0;
    
    int leftMax = dfs(root->left, res);
    int rightMax = dfs(root->right, res);
    leftMax = max(leftMax, 0);
    rightMax = max(rightMax, 0);

    // Compute max path sum WITH split
    res[0] = max(res[0], root->val + leftMax + rightMax);

    // Return the max path sum WITHOUT split
    return root->val + max(leftMax, rightMax);
}

// Helper Function to create a binary tree from a level-order input
TreeNode* createBinaryTree(const vector<int>& values) {
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
void printBinaryTree(TreeNode* root) {
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