class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>output;
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<n;j++){
                int p=j+1,q=n-1;
                while(p<q){
                    long long sum=(long long)nums[i]+nums[j]+nums[p]+nums[q];
                if(sum==target){
                    s.insert({nums[i],nums[j],nums[p],nums[q]});
                    p++;
                    q--;
                }
                else if(sum<target){
                    p++;
                }
                else{
                    q--;
                }
                }
            }

        }
    for (auto i : s){
        output.push_back(i);
    }
    return output;
    }
    
};