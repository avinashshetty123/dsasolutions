class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=nums[i];
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j=i+l-1;
                int pickL=nums[i]-dp[i+1][j];
                int pickR=nums[j]-dp[i][j-1];
                dp[i][j]=max(pickL,pickR);
            }
        }
        return dp[0][n-1]>=0;
        
    }
};