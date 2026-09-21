class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>res(k,0);
        vector<long long>dp(k,0);
        for(int i:nums){
            vector<long long>nextd(k,0);
            int mod=i%k;
            nextd[mod]++;
            for(int r=0;r<k;r++){
                if(dp[r]>0){
                    int newr=(r*mod)%k;
                    nextd[newr]+=dp[r];
                }
            }
            for(int r=0;r<k;r++){
                res[r]+=nextd[r];
            }
            dp=move(nextd);
        }
        return res;
    }
};