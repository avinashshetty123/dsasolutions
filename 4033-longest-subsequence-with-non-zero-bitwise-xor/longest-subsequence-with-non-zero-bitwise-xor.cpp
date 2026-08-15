class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=0;
        bool hasN=false;
        for(int i:nums){
            ans^=i;
            if(i!=0){
                hasN=true;
            }
        }
        if(!hasN)return 0;
        if(ans!=0)return nums.size();
        return nums.size()-1;
    }
};