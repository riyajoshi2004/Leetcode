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
    vector<int>solve(TreeNode* root,int &ans){
        if(root==nullptr){
            return {1,INT_MAX,INT_MIN,0};
        }
        vector<int> left=solve(root->left,ans);
        vector<int> right=solve(root->right,ans);
        if(left[0] && right[0] && left[2] < root->val && root->val < right[1]){
            int sum=left[3] + right[3] + root->val;
            ans=max(ans,sum);
            int mini=min(left[1],root->val);
            int maxi=max(right[2],root->val);
            return{1,mini,maxi,sum};

        }
        return{0,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};