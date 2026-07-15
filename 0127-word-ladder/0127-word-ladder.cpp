class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginword,1});
        if(st.find(endword)==st.end()){
            return 0;
        }
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endword){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);//visited
                    }
                }
            word[i]=original;
            }
        }
        return 0;
    }
};