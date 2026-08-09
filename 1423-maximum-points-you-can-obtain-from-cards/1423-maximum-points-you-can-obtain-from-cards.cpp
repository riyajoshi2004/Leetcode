class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum=0;
        for(int x : cardPoints){
        totalSum+=x;
    }
    int windowsize=n-k;
    if(windowsize==0)
        return totalSum;
    int windowsum=0;
    for(int i=0;i<windowsize;i++){
        windowsum+=cardPoints[i];
    }
    int miniwindowsum=windowsum;
    for(int i=windowsize;i<n;i++){
        windowsum+=cardPoints[i];
        windowsum-=cardPoints[i-windowsize];
        miniwindowsum=min(miniwindowsum,windowsum);
    }
    return totalSum-miniwindowsum;
    }
};