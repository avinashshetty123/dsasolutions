class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
       unordered_set<int>st(nums.begin(),nums.end());
       unordered_set<int>pair;
       for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            pair.insert(nums[i]^nums[j]);
        }
       }
       unordered_set<int>trip;
       for(int p:pair){
        for(int i:st){
            trip.insert(p^i);
        }
       }
       return trip.size();
        
        
    }
};