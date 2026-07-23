class segmenttree{
private:
    int n;
    vector<int> arr;
    vector<int> seg;
    void build(int p,int l,int r){
        if(l==r){
            seg[p]=arr[l];
            return;
        }
        int mid=(l+r)>>1;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        seg[p]=max(seg[p<<1],seg[p<<1 | 1]);
    }
    int _query(int p , int l,int r,int L,int R){
        if(L<=l && r<=R){
            return seg[p];
        }
        int mid=(l+r)>>1;
        int res=0;
        if(L<=mid){
            res=max(res,_query(p<<1,l,mid,L,R));
        }
        if(R>mid){
            res=max(res,_query(p<<1 | 1,mid+1,r,L,R));
        }
    
        return res;
    }
public:
    segmenttree(const vector<int>& arr) : arr(arr) {
        n = arr.size();
        seg.resize(n << 2, 0);
        build(1, 0, n - 1);
    }

    int query(int L, int R) {
        if (L > R) {
            return 0;
        }

        return _query(1, 0, n - 1, L, R);
    }

};
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n=s.length();
        int cnt1=count(s.begin(),s.end(),'1');
        vector<int> zeroBlocks;
        vector<int> blockleft;
        vector<int> blockright;

        int i=0;
        while(i<n){
            int st=i;
            while(i<n && s[i]==s[st]){
                i+=1;
            }
            if(s[st]=='0'){
                zeroBlocks.push_back(i-st);
                blockleft.push_back(st);
                blockright.push_back(i-1);
            }
        }
        int m=zeroBlocks.size();
        if(m<2){
            return vector<int>(queries.size(),cnt1);
        }
        vector<int> tmpsum(m-1);
        for(int i=0;i<m-1;i++){
            tmpsum[i]=zeroBlocks[i]+zeroBlocks[i+1];
        }
        segmenttree seg(tmpsum);
        vector<int> ans;
        for(const auto& q:queries){
            int l=q[0],r =q[1];
            int i=lower_bound(blockright.begin(),blockright.end(),l)-blockright.begin();
            int j=upper_bound(blockleft.begin(),blockleft.end(),r)-blockleft.begin()-1;
            if(i>m-1 || j<0 || i>=j){
                ans.push_back(cnt1);
                continue;
            }
            int firstlen=blockright[i]-max(blockleft[i],l)+1;
            int lastlen=min(blockright[j],r)-blockleft[j]+1;
            if(i+1==j){
                int bestgain=firstlen+lastlen;
                ans.push_back(cnt1+bestgain);
                continue;

            }
            int val1=firstlen + zeroBlocks[i+1];
            int val2=zeroBlocks[j-1]+lastlen;
            int val3=seg.query(i+1,j-2);
            int bestgain=max({val1,val2,val3});
            ans.push_back(cnt1+bestgain);
        }
        return ans;
    }
};