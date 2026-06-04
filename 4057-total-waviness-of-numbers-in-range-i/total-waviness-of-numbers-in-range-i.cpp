class Solution {
public:
    int solve(int x) {
        int cnt = 0;
        string s = to_string(x);
        for (int i = 1; i + 1 < s.size(); i++) {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                s[i] < s[i - 1] && s[i] < s[i + 1]) {
                cnt++;
            }
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        long long ans = 0;
        for (int i = num1; i <= num2; i++)
            ans += solve(i);
        return ans;
    }
};