class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(int i:nums){
            total+=i;
        }
        int target=total-x;
        if(target==0)return nums.size();
        if(target<0)return -1;
        int left=0;
        int curr=0;
        int maxi=-1;
        for(int r=0;r<nums.size();r++){
            curr+=nums[r];
            while(left<=r&&curr>target){
                curr-=nums[left];
                left++;
            }
            if(curr==target){
                maxi=max(maxi,r-left+1);
            }
        }
        return maxi==-1?-1:nums.size()-maxi;
    }
};