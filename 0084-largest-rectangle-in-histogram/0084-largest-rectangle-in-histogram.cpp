class Solution {
public:
    vector<int>prevSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int>st;
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<= heights[st.top()] ){
                st.pop();
            }
            if(st.empty())
                pse[i]=-1;
            else
                pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int>nextSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]< heights[st.top()] ){
                st.pop();
            }
            if(st.empty())
                nse[i]=n;
            else
                nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        vector<int>pse=prevSmaller(heights);
        vector<int>nse=nextSmaller(heights);
        for(int i=0;i<n;i++){
            int width=nse[i]-pse[i]-1;
            ans=max(ans,heights[i]*width);
        }
        return ans;
    }
};