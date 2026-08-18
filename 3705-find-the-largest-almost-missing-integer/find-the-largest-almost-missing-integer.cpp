class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
       int n=nums.size();
       unordered_map<int,int>mp;
       for(int i:nums){
        mp[i]++;
       }
       if(k==1){
        int maxi=-1;
        for(auto &[i,c]:mp){
            if(c==1){
                maxi=max(maxi,i);
            }
        }
        return maxi;
       }
       if(k==n){
        int maxi=-1;
        for(int i:nums){
            maxi=max(maxi,i);
        }
        return maxi;
       }
       int maxi=-1;
       if(mp[nums[0]]==1)maxi=max(maxi,nums[0]);
       if(mp[nums[n-1]]==1)maxi=max(maxi,nums[n-1]);
       return maxi;
    }
};