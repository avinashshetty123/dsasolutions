class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()<1)return {};
        unordered_map<int, int> mp;
        vector<int> res(arr.begin(), arr.end());
        sort(res.begin(), res.end());
        int cnt = 1;
        mp[res[0]]=1;
        for (int i = 1; i < arr.size(); i++) {
            if (res[i] == res[i - 1]) {
                mp[res[i]] = cnt;
            } else {

                mp[res[i]] = ++cnt;
            }
        }
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};