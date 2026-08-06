class Solution {
public:
    vector<int> prevGreaterEle(vector<int>&nums){
        int n=nums.size();
        vector<int>pge(n);
        stack<int>st;
        for(int i=0 ;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            pge[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pge;
    }
    vector<int> nextGreaterEle(vector<int>&nums){
        int n=nums.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=n-1 ;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            nge[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> prevSmallerEle(vector<int>&nums){
        int n=nums.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0 ;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> nextSmallerEle(vector<int>&nums){
        int n=nums.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1 ;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>pgee=prevGreaterEle(nums);
        vector<int>nge=nextGreaterEle(nums);
        vector<int>psee=prevSmallerEle(nums);
        vector<int>nse=nextSmallerEle(nums);
        
        long long maxSum=0;
        long long minSum=0;
        for(int i=0;i<n;i++){
            long long left=i-pgee[i];
            long long right=nge[i]-i;
            maxSum+=1LL*nums[i]*left*right;
        }
        for(int i=0;i<n;i++){
            long long left=i-psee[i];
            long long right=nse[i]-i;
            minSum+=1LL*nums[i]*left*right;
        }
        return maxSum-minSum;
    }
};