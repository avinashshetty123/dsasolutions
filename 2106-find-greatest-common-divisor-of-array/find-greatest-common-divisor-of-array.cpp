class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=0;
        for(int i:nums){
            mini=min(i,mini);
            maxi=max(i,maxi);
        }
        return __gcd(mini,maxi);
        
    }
};