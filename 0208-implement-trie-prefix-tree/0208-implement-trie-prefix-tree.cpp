struct Node{
    bool flag;
    Node* child[26];
    Node(){
        flag=false;
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        int len=word.size();
        Node* dum=root;
        for(int i=0;i<len;i++){
            int inx=word[i]-'a';
            if(!dum->child[inx]){
                dum->child[inx]=new Node();
            }
            dum=dum->child[inx];
        }
        dum->flag=true;
    }
    
    bool search(string word) {
        int n=word.size();
        Node* dum=root;
        for(int i=0;i<n;i++){
            int inx=word[i]-'a';
            if(!dum->child[inx]){
                return false;
            }
            dum=dum->child[inx];
        }
        return dum->flag;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        Node* dum=root;
        for(int i=0;i<n;i++){
            int inx=prefix[i]-'a';
            if(!dum->child[inx]){
                return false;
            }
            dum=dum->child[inx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */