// morris traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode * curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* p=curr->left;
                while(p->right&& p->right!=curr){
                    p=p->right;
                }
                if(p->right==NULL){
                    p->right=curr;
                    curr=curr->left;
                }
                else{
                    p->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;   
                }
            }
        }
        return inorder;
    }
};