class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0];
        bool hasOdd = false;
        for (int i : nums1) {
            if (i < mn) {
                mn = i;
            }
            if (i & 1) {
                hasOdd = true;
            }
        }
        if (mn & 1)
            return true;
        return !hasOdd;
    }
};