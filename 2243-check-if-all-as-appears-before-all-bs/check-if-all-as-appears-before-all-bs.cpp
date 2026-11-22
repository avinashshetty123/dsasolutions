class Solution {
public:
    bool checkString(string s) {
        bool seenB = false;
        for (char c : s) {
            if (c == 'a' && seenB) {
                return false;
            }
            if (c == 'b') {
                seenB = true;
            }
        }
        return true;
    }
};