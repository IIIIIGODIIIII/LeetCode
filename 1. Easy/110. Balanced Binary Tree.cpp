#include <iostream>
#include <bits/stdc++.h>

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
bool isBalanced(TreeNode* root);
int checkNode(TreeNode* root); 

int main()
{
    vector<int> values = {3,9,20,-1,-1,15,7}; 
    TreeNode* root = createBinaryTree(values);
    bool res;

    res = isBalanced(root);
    cout<<res;
    return 0;
}

bool isBalanced(TreeNode* root){
    int height = checkNode(root);
    if(height == -1)
        return false;
    else 
        return true;
}

int checkNode(TreeNode* root){
    if (root == NULL)
            return 0;

        int lh = checkNode(root->left);
        if(lh == -1)
            return -1;

        int rh = checkNode(root->right);
        if(rh == -1)
            return -1;

        if (abs(lh - rh) > 1)
            return -1;
        
        return 1 + max(lh, rh);
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