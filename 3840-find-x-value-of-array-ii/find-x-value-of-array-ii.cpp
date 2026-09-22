class SegmentTree{
    private:
    static const int MAXK=6;
    int k;
    int n;
    vector<array<int,MAXK>>tree;
    void makeLeaf(int o,int val){
        tree[o].fill(0);
        int r=val%k;
        tree[o][r]=1;
        tree[o][k]=r;
    }
    void mergePre(const array<int,MAXK>&left,const array<int,MAXK>&right,array<int,MAXK>&res){
    res.fill(0);
    int mulL=left[k];
    int mulR=right[k];
    res[k]=(mulL*mulR)%k;
    for(int x=0;x<k;x++){
        res[x]=left[x];
    }
    for(int x=0;x<k;x++){
        res[(mulL*x)%k]+=right[x];
    }
    }
    void maintain(int o){
        mergePre(tree[o*2],tree[o*2+1],tree[o]);
    }
    void build(const vector<int>&nums,int o,int l,int r){
        if(l==r){
            makeLeaf(o,nums[l]);
            return;
        }
        int m=(l+r)/2;
        build(nums,o*2,l,m);
        build(nums,o*2+1,m+1,r);
        maintain(o);
    }
    public:
    SegmentTree(const vector<int>&nums,int k):k(k),n(nums.size()){
        int size=2<<(int)ceil(log2(n));
        tree.resize(size);
        build(nums,1,0,n-1);
    }
    void update(int o,int l,int r,int index,int val){
        if(l==r){
            makeLeaf(o,val);
            return;
        }
        int m=(l+r)/2;
        if(index<=m){
            update(o*2,l,m,index,val);
        }else{
            update(o*2+1,m+1,r,index,val);
        }
        maintain(o);
    }
    array<int,MAXK>query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return tree[o];
        }
        int m=(l+r)/2;
        if(R<=m){
            return query(o*2,l,m,L,R);
        }
        if(L>m){
            return query(o*2+1,m+1,r,L,R);
        }
        array<int,MAXK>left=query(o*2,l,m,L,R);
        array<int,MAXK>right=query(o*2+1,m+1,r,L,R);
        array<int,MAXK>res;
        mergePre(left,right,res);
        return res;
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        SegmentTree seg(nums,k);
        vector<int>ans;
        for(auto &q:queries){
            int index=q[0],val=q[1],start=q[2],x=q[3];
            seg.update(1,0,n-1,index,val);
            auto pre=seg.query(1,0,n-1,start,n-1);
            ans.push_back(pre[x]);
        }
        return ans;
        
    }
};