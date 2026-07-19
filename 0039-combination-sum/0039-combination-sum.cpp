class Solution {
public:
    set<vector<int>>s;
    void getallcomb(vector<int>&cand,int idx,int tar,vector<int>&comb,vector<vector<int>>&ans){
        if(tar==0) {
            if(s.find(comb)==s.end()){
            ans.push_back(comb);
            s.insert(comb);
            return;
            }
        }
        if(idx==cand.size() || tar<0) return;
        
        comb.push_back(cand[idx]);
        // getallcomb(cand,idx+1,tar-cand[idx],comb,ans);
        getallcomb(cand,idx,tar-cand[idx],comb,ans);

        comb.pop_back();
        getallcomb(cand,idx+1,tar,comb,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        int n=cand.size();
        vector<vector<int>>ans;
        vector<int>comb;
        getallcomb(cand,0,target,comb,ans);
        return ans;
        
    }
};