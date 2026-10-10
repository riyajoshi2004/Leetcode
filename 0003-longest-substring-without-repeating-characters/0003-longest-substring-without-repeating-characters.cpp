class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxLen=0;
        unordered_map<char,int>mpp;
        for(r=0;r<n;r++){
            char c=s[r];
            if(mpp.count(c) && mpp[c]>=l){
                l=mpp[c]+1;
            }
            mpp[c]=r;
            int len=r-l+1;
            maxLen=max(maxLen,len);
        }
        return maxLen;
    }
};