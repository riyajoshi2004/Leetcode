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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return nullptr;
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return Build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }
    TreeNode* Build(vector<int>& postorder,int ps,int pe,vector<int>& inorder,int is,int ie,map<int,int>& mpp){
        if(ps>pe || is>ie) return nullptr;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = mpp[postorder[pe]];
        int numsLeft=inRoot-is;
        root->left=Build(postorder, ps, ps + numsLeft - 1,inorder, is, inRoot - 1, mpp);
        root->right=Build( postorder, ps + numsLeft, pe - 1,inorder, inRoot + 1, ie, mpp);

        return root;
    }
};