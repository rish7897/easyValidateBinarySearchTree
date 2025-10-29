#include<iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// inorder traversal
bool isValidBST(TreeNode* root, TreeNode* &prev) {
    if(root == NULL){
        return true;
    }
    if(!isValidBST(root->left, prev)){
        return false;
    }
    if(prev != NULL && root->val <= prev->val){
            return false;   
        }
    prev = root;
    return isValidBST(root->right, prev);
}
bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    return isValidBST(root, prev);
}