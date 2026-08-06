class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=0,rightmax=0,ans=0;
        int l=0;
        int n=height.size();
        int r=n-1;
        while(l<r){
            if(height[l]<height[r]){
                if(leftmax>height[l]){
                    ans+=leftmax-height[l];
                }
                else{
                    leftmax=height[l];
                }
                l++;
            }
            else{
                if(rightmax>height[r]){
                    ans+=rightmax-height[r];
                }
                else{
                    rightmax=height[r];
                }
                r--;
            }
        }
        return ans;
    }
};