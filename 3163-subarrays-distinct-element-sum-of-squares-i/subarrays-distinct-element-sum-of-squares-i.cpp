class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>dis;
            for(int j=i;j<nums.size();j++){
                dis.insert(nums[j]);
                int cnt=dis.size();
                ans+=cnt*cnt;
            }
        }
        return ans;
        
    }
};