class Solution {
public:
    int rev(int num){
        int ans=0;
        while(num>0){
            int rem=num%10;
            ans=(ans*10)+rem;
            num=num/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int M=1e9+7;
        int result=0;
        unordered_map<int,int>map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-rev(nums[i]);
        }
        for(int i=0;i<n;i++){
            result=(result+map[nums[i]])%M;
            map[nums[i]]++;
        }
        return result;
    }
};