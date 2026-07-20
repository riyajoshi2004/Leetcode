class Solution {
public:
    bool isvalid(vector<vector<int>>& grid,int expval,int r, int c,int n){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expval){
            return false;
        }
        if(expval==n*n-1){
            return true;
        }

        int ans1=isvalid(grid,expval+1,r-2,c+1,n);
        int ans2=isvalid(grid,expval+1,r-2,c-1,n);
        int ans3=isvalid(grid,expval+1,r+2,c+1,n);
        int ans4=isvalid(grid,expval+1,r+2,c-1,n);
        int ans5=isvalid(grid,expval+1,r-1,c+2,n);
        int ans6=isvalid(grid,expval+1,r-1,c-2,n);
        int ans7=isvalid(grid,expval+1,r+1,c+2,n);
        int ans8=isvalid(grid,expval+1,r+1,c-2,n);

        return ans1|| ans2 ||  ans3 || ans4|| ans5|| ans6|| ans7|| ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isvalid(grid,0,0,0,grid.size());
    }
};