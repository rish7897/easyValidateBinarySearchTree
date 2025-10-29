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


// inner pair's first is min and second is max
// outer pair's first is pair of min and max and second is bool(bst or not)
pair<pair<int, int>, bool> findMinMaxAndIsValidBST(TreeNode* root){
    pair<pair<int, int>, bool> ans;
    // pair : min max
    ans.second = true;
    
    if(root == NULL){
        return ans;
    }
    
    pair<pair<int, int>, bool> leftAns = findMinMaxAndIsValidBST(root->left);
    pair<pair<int, int>, bool> rightAns = findMinMaxAndIsValidBST(root->right);
    
    if(root->left == NULL && root->right == NULL){
        ans.first.first = root->val;
        ans.first.second = root->val;
        ans.second = true;
        return ans;
    }
    
    if(root->left == NULL && rightAns.second && root->val < rightAns.first.first){
        ans.first.first = root->val;
        ans.first.second = rightAns.first.second;
        ans.second = true;
        return ans;
    }
    if(root->right == NULL && leftAns.second && root->val > leftAns.first.second){
        ans.first.first = leftAns.first.first;
        ans.first.second = root->val;
        ans.second = true;
        return ans;
    }
    
    if(leftAns.second && rightAns.second && root->val > leftAns.first.second && root->val < rightAns.first.first){
        ans.first.first = leftAns.first.first;
        ans.first.second = rightAns.first.second;
        ans.second = true;
        return ans;
    }
    ans.second = false;
    return ans;
}
bool isValidBST(TreeNode* root) {
    return findMinMaxAndIsValidBST(root).second;
}