class Solution {
public:
    bool isPalin(string s){
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
    void getallparts(string str,vector<vector<string>>&ans,vector<string>&partitions){
        if(str.size()==0){
            ans.push_back(partitions);
            return;
        }
        for(int i=0;i<str.size();i++){
            string part=str.substr(0,i+1);
            if(isPalin(part)){
                partitions.push_back(part);
                getallparts(str.substr(i+1),ans,partitions); 
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partitions;
        getallparts(s,ans,partitions);
        return ans;
    }
};