class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ls=0;
        int rs=0;
        for(int num : nums){
            rs+=num;
        }
        
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            int rs=rs-val;
            if(rs==ls){
                return i;
            }
            ls+=val;

        }
    return -1;
    }
};