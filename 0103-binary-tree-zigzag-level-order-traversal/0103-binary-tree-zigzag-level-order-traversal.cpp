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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if (root==nullptr) return result;
        queue<TreeNode*>q;
        q.push(root);
        bool LtoR=true;
        while(!q.empty()){
            int s=q.size();
            vector<int>level(s);
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                int index=LtoR ? i : s-1-i;
                level[index]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            LtoR=!LtoR;
            result.push_back(level);
        }
    return result;
    }
};