class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=min_element(nums.begin(),nums.end())-nums.begin();
        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
      int L=min(mini,maxi);
      int R=max(mini,maxi);
      int both_L=R+1;
      int both_R=nums.size()-L;
      int lr=(L+1)+(nums.size()-R);
      return min({both_L,both_R,lr});
    }
};