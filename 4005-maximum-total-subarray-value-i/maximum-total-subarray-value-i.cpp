class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
     int maxi=nums[0];
     int mini=nums[0];
     for(int i:nums){
        if(i>maxi)maxi=i;
        if(i<mini)mini=i;
     }
     return (long long)k*(maxi-mini); 
    }
};