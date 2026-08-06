class Solution {
public:
    int largestRectangleArea(vector<int>&heights){  //for one row
        stack<int>st;
        int n=heights.size();
        int MaxArea=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int height=heights[st.top()];
                st.pop();
                int pse=st.empty()?-1:st.top();
                int nse=i;
                int width=nse-pse-1;
                MaxArea=max(MaxArea,height*width);
            }
            st.push(i);
        }
        return MaxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int>heights(cols,0);
        int ans=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else
                    heights[j]=0;
    
            }
            ans=max(ans,largestRectangleArea(heights));
        }
    return ans;
    }
};