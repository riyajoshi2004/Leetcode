class Solution {
public:
    const int MOD=1e9+7;
    vector<int> psee(vector<int>& arr){
        int n=arr.size();
        vector<int> prev(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty())
                prev[i]=-1;
            else
                prev[i]=st.top();
            st.push(i);
        }
        return prev;
    }
    vector<int> nse(vector<int>& arr){
        int n=arr.size();
        vector<int>next(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& arr[st.top()]>=arr[i])
                st.pop();
            if(st.empty())
                next[i]=n;
            else
                next[i]=st.top();
            st.push(i);
        }
        return next;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>prev=psee(arr);
        vector<int>next=nse(arr);
        long long ans=0;
        for(int i=0;i<n;i++){
            long long left=i-prev[i];
            long long right=next[i]-i;
            ans=(ans+(left*right%MOD)*arr[i])%MOD;
        }
        return ans;
    }
};