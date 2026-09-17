class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>dp(n,INT_MAX/2);
        int left=0;
        int ans=INT_MAX/2;
        int mini=INT_MAX/2;
        int sum=0;
        for(int r=0;r<arr.size();r++){
            sum+=arr[r];
            while(sum>target){
                sum-=arr[left];
                left++;
            }
            if(sum==target){
                int len=r-left+1;
                if(left>0){
                    ans=min(ans,len+dp[left-1]);
                }
                mini=min(mini,len);
            }
            dp[r]=mini;
           
            
        }
        return ans>=INT_MAX/2?-1:ans;
        
    }
};