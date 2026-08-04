class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.size() < 2)
            return {};
        vector<int> ans;
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        unordered_set<int> mp(nums.begin(), nums.end());
        for (int i = mini; i <= maxi; i++) {

            if (mp.find(i) == mp.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};