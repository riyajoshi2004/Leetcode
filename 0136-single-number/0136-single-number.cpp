class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;   
        }
        for(auto i : map ){
            if(i.second==1){
                ans=i.first;
            }
        }
        return ans;
    }

};