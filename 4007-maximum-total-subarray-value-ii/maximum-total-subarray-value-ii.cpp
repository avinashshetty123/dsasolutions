class Solution {
public:
vector<vector<int>> st_min;
    vector<vector<int>> st_max;
    vector<int> lg;

    void buildSparseTable(const vector<int>& nums) {
        int n = nums.size();
        int max_log = log2(n) + 1;
        
        st_min.assign(n, vector<int>(max_log));
        st_max.assign(n, vector<int>(max_log));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            st_min[i][0] = nums[i];
            st_max[i][0] = nums[i];
        }

        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // Helper to get subarray value in O(1)
    long long getSubarrayValue(int l, int r) {
        int j = lg[r - l + 1];
        int mn = min(st_min[l][j], st_min[r - (1 << j) + 1][j]);
        int mx = max(st_max[l][j], st_max[r - (1 << j) + 1][j]);
        return (long long)mx - mn;
    }
    long long maxTotalValue(vector<int>& nums, int k) {
      int n = nums.size();
        buildSparseTable(nums);

        // Max-Heap stores elements as: {value, {l, r}}
        priority_queue<pair<long long, pair<int, int>>> pq;

        // Step 2: Push the maximum subarray for each starting point 'l'
        for (int l = 0; l < n; l++) {
            long long val = getSubarrayValue(l, n - 1);
            pq.push({val, {l, n - 1}});
        }

        long long total_value = 0;

        // Step 3: Extract the top k elements
        while (k > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            long long val = top.first;
            int l = top.second.first;
            int r = top.second.second;

            total_value += val;
            k--;

            // If we can shrink the right pointer further, push the next candidate
            if (r > l) {
                long long next_val = getSubarrayValue(l, r - 1);
                pq.push({next_val, {l, r - 1}});
            }
        }

        return total_value;
    }
};