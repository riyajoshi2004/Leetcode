class Solution {
public:
    int helper(vector<int>& nums, int k){
        if(k<0) return 0;
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        while(r<nums.size()){
            sum=sum+(nums[r]%2); //add 0 if even , add 1 if odd
            while(sum>k){
                sum=sum-(nums[l]%2);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};