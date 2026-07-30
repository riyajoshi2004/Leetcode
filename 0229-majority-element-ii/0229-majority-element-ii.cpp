class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0 ,cnt2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        int mini=(int)(nums.size()/3);
        vector<int>ans;
        for (int i =0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=ele2){
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1){
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1){
                cnt1++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int count1=0 , count2=0;
        for(int i=0;i<nums.size();i++){
            if(ele1==nums[i]) count1++;
            if(ele2==nums[i]) count2++;
        }
        if(count1>mini ) ans.push_back(ele1);
        if(count2>mini  ) ans.push_back(ele2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};