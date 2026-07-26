class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()<3)return 1;
        int ans=1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int op1=nums[n-1]*nums[n-2]*nums[n-3];
        int op2=nums[0]*nums[1]*nums[n-1];
        return max(op1,op2);

    }
};