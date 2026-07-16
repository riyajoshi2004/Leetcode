class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //longest prefix
        int n=nums.size();
        int pvt=-1;
        for(int i=n-2;i>=0;i--){  // start with n-1 also but it doesnt reflect any change
            if(nums[i]<nums[i+1]){
                pvt=i;
                break;
            }
        }
        if(pvt==-1) {
            reverse(nums.begin(),nums.end());
            return; //in-place
        }
        for(int i=n-1;i>pvt;i--){
            if(nums[i]>nums[pvt]){
                swap(nums[i],nums[pvt]);
                break;
            }
        }
        int i =pvt+1,j=n-1;
        while(i<=j){
            swap(nums[i++],nums[j--]);
        }
    }
};