#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n == 0) return 0;

        // Map values to positive 1-based IDs so 0 never collapses under multiplication
        vector<int> sorted_vals = nums;
        sort(sorted_vals.begin(), sorted_vals.end());
        sorted_vals.erase(unique(sorted_vals.begin(), sorted_vals.end()), sorted_vals.end());

        auto get_id = [&](int x) -> uint64_t {
            int idx = static_cast<int>(lower_bound(sorted_vals.begin(), sorted_vals.end(), x) - sorted_vals.begin());
            return static_cast<uint64_t>(idx) + 1;
        };

        // Base greater than max element ID (n + 1 is at most 100,002)
        const uint64_t BASE1 = 1315423911ULL;
        const uint64_t MOD1 = 1000000007ULL;

        const uint64_t BASE2 = 2654435761ULL;
        const uint64_t MOD2 = 1000000009ULL;

        vector<uint64_t> pref1(n + 1, 0), pow1(n + 1, 1);
        vector<uint64_t> pref2(n + 1, 0), pow2(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            uint64_t val = get_id(nums[i]);
            pref1[i + 1] = (pref1[i] * BASE1 + val) % MOD1;
            pow1[i + 1] = (pow1[i] * BASE1) % MOD1;

            pref2[i + 1] = (pref2[i] * BASE2 + val) % MOD2;
            pow2[i + 1] = (pow2[i] * BASE2) % MOD2;
        }

        auto get_hash = [&](int l, int r) -> uint64_t {
            // Subarray is nums[l .. r - 1] of length (r - l)
            int len = r - l;
            uint64_t h1 = (pref1[r] + MOD1 - (pref1[l] * pow1[len]) % MOD1) % MOD1;
            uint64_t h2 = (pref2[r] + MOD2 - (pref2[l] * pow2[len]) % MOD2) % MOD2;
            return (h1 << 32) | h2;
        };

        auto has_unique_of_len = [&](int len) -> bool {
            unordered_map<uint64_t, int> freq;
            freq.reserve(static_cast<size_t>(n - len + 1) * 2);

            for (int l = 0; l + len <= n; ++l) {
                uint64_t h = get_hash(l, l + len);
                ++freq[h];
            }

            for (const auto& [_, cnt] : freq) {
                if (cnt == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (has_unique_of_len(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};