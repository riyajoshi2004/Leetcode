class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;
        int lh=getHeight(root->left);
        int rh=getHeight(root->right);
        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
    int getHeight(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int lh=getHeight(root->left);
        int rh=getHeight(root->right);
        return max(lh,rh)+1;
    }
};