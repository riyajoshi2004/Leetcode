/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapParentNodes(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parentMap){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parentMap[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parentMap[node->right]=node;
                q.push(node->right);
            }

        }
    }
    vector<int>bfsFromTarget(TreeNode* target,unordered_map<TreeNode*,TreeNode*>& parentMap,int k){
        queue<TreeNode*>q;
        unordered_set<TreeNode*>visited;
        q.push(target);
        visited.insert(target);
        int cur_lvl=0;
        while(!q.empty()){
            int size=q.size();
            if(cur_lvl++ ==k) break;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && visited.find(node->left) ==visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && visited.find(node->right) ==visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parentMap.count(node) && visited.find(parentMap[node])==visited.end()){
                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return{};
        unordered_map<TreeNode*,TreeNode*>parentMap;
        mapParentNodes(root,parentMap);
        return bfsFromTarget(target,parentMap,k);
    }
};