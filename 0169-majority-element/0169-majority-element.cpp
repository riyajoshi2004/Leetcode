class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size();
        int k=n/2;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            if(map[nums[i]]>k){
                return nums[i];
            }
        }
    return -1;
    }
};