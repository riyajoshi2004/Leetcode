class Solution {
public:
    int numberOfSubstrings(string s) {
        int LastSeen[3]={-1,-1,-1};
        int cnt=0;
        for(int i=0;i<s.size();i++){
            LastSeen[s[i]-'a']=i;//store index
            if(LastSeen[0]!=-1 && LastSeen[1]!=-1 && LastSeen[2]!=-1){
                cnt=cnt+(1+min({LastSeen[0],LastSeen[1],LastSeen[2]}));
            }
        }
        return cnt;
    }
};