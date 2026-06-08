class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        vector<int> left;
        vector<int> right;
        vector<int> mid;
        for (int i : nums) {
            if (i == pivot) {
                mid.push_back(i);
            } else if (i< pivot) {
                left.push_back(i);

            } else {
                right.push_back(i);
            }
        }
        for (int i : left) {
            ans.push_back(i);
        }
        for (int i : mid) {
            ans.push_back(i);
        }
        for (int i : right) {
            ans.push_back(i);
        }
        return ans;
    }
};