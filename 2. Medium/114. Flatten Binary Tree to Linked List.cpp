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
void flatten(TreeNode* root);
TreeNode* dfs(TreeNode* root);

int main()
{
    vector<int> list={1,2,5,3,4,-1,6};
    TreeNode* root = createBinaryTree(list);
    flatten(root);
    printBinaryTree(root);
   
   return 0;
}

void flatten(TreeNode* root){
    dfs(root);
}

TreeNode* dfs(TreeNode* root){
    if(root==NULL)
        return NULL;

    TreeNode *leftTail = dfs(root->left);
    TreeNode *rightTail = dfs(root->right);

    if(root->left != NULL){
        leftTail->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }

    TreeNode* last = rightTail? rightTail : (leftTail? leftTail : root);

    return last;
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