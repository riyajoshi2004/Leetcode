/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return checkValidity(root,LLONG_MIN,LLONG_MAX);
    }
    bool checkValidity(TreeNode* root,long long left,long long right){
        if(root==NULL) return true;
        if(root->val<=left || root->val>=right) return false;
        return checkValidity(root->left,left,root->val) && checkValidity(root->right,root->val,right);
    }
};