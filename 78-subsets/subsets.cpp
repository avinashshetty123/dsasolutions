class Solution {
public:
vector<vector<int>>ans;
void solve(vector<int>&nums,vector<int>&curr,int idx){
if(idx==nums.size()){
    ans.push_back(curr);
    return;
}
int val=nums[idx];
curr.push_back(val);
solve(nums,curr,idx+1);
curr.pop_back();
solve(nums,curr,idx+1);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
   solve(nums,curr,0);
   return ans;
    }
};