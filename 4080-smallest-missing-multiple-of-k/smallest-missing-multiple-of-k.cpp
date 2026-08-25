class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i=k;
        unordered_set<int>st(nums.begin(),nums.end());
        int j=1;
        while(st.find(i)!=st.end()){
            i=k*j;
            j++;
       
        }
        return i;
    }
};