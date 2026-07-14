class Solution {
public:
    const int MOD = 1e9 + 7;
    int total = 0;
    int memo[201][201][201];
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int solve(int idx, int g1, int g2, vector<int>& nums) {
        if (idx == nums.size()) {
            if (g1 > 0 && g2 > 0 && g1 == g2) {
                return 1;
            }
            return 0;
        }
        if (memo[idx][g1][g2] != -1) {
            return memo[idx][g1][g2];
        }
        int next_g1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        long long ways = solve(idx + 1, next_g1, g2, nums);
        int next_g2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        ways = (ways + solve(idx + 1, g1, next_g2, nums)) % MOD;
        ways = (ways + solve(idx+1, g1, g2, nums)) % MOD;
        return memo[idx][g1][g2] = ways;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, nums);
    }
};