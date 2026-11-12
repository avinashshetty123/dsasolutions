class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            int curr = 1;
            for (int p = i + 1; p < nums.size(); p++) {
                if (nums[p] > nums[p - 1]) {
                    curr++;
                } else {
                    break;
                }
            }
            maxi = max(maxi, curr);
        }
        for (int i = 0; i < nums.size(); i++) {
            int curr = 1;
            for (int p = i + 1; p < nums.size(); p++) {
                if (nums[p] < nums[p - 1]) {
                    curr++;
                } else {
                    break;
                }
            }
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};