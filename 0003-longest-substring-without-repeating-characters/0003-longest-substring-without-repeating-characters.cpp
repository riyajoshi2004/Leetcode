class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxLen=0;
        unordered_set<char>st;
        for(r=0;r<n;r++){
            char c=s[r];
            while(st.count(c)){
                st.erase(s[l]);
                l++;
            }
            st.insert(c);
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};