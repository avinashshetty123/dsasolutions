class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int maxi=0;
        int left = 0;
        for (int r = 0; r < s.size(); r++) {
            while(hash.find(s[r])!=hash.end()){
                hash.erase(s[left]);
                left++;
            }
            hash.insert(s[r]);
            maxi=max(maxi,r-left+1);

        }
        return maxi;
    }
};