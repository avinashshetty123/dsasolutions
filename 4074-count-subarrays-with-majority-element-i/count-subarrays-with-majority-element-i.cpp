class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int count = 0;
        int n=nums.size();
        int j;
        for (int i = 0; i < n; i++) {

            int cnt = 0;
            for ( j = i; j < n; j++) {
                if (nums[j] == target) {
                    cnt++;
                }
            int sub = (j - i + 1);
            if (2 * cnt > sub) {
                count++;
            }
            }
        }
        return count;
    }
};