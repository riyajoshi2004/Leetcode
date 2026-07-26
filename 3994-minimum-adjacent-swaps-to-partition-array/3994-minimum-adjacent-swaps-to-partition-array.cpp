class Solution {
public:
    int mod = 1e9 + 7; 
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
      
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < a) nums[i] = 0; 
            else if(nums[i] > b) nums[i] = 2; 
            else nums[i] = 1; 
        }
        long long cnt1 = 0, cnt2 = 0; 
        long long swaps = 0; 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                // this must cross all 1's and 2's before it
                swaps = (swaps + cnt1 + cnt2) % mod; 
            } else if(nums[i] == 1) {
                // must corss all cnt2 befor it 
                swaps = (swaps + cnt2) % mod; 
                cnt1++; 
            } else cnt2++; 
        }
        return swaps; 
    }
};