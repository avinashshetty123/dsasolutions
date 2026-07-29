class Solution {
public:
long long comb(long long n,long long m,long long k){
    long long res=1;
    m=min(m,n-m);
    for(long long i=1;i<=m;i++){
        res=res*(n-i+1)/i;
        if(res>k){
            return k+1;
        }
    }
    return res;
}
    string smallestPalindrome(string s, int k) {
        int partition=s.length()/2;
        vector<int>bucket(26,0);
        for(int i=0;i<partition;i++){
            bucket[s[i]-'a']++;
        }
        auto permutation=[&](int r){
            long long ways=1;
            for(int i=0;i<26;i++){
                if(bucket[i]==0){
                    continue;
                }
                ways*=comb(r,bucket[i],k);
                if(ways>k)break;
                r-=bucket[i];
                
            }
            return ways;
        };
        string left="";
        long long startIdx=1;
        for(int p=0;p<partition;p++){
            for(int i=0;i<26;i++){
                if(bucket[i]==0)continue;
                bucket[i]-=1;
                long long ways=permutation(partition-p-1);
                if(startIdx+ways>k){
                    left+=(char)(i+'a');
                    break;
                }
                bucket[i]+=1;
                startIdx+=ways;
            }
        }
        if(left.length()<partition){return "";}
        string mid=s.length()%2!=0?string(1,s[partition]):"";
        string right=left;
        reverse(right.begin(),right.end());
        return left+mid+right;
        
    }
};