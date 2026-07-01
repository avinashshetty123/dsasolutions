class Solution {
public:
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Edge case: If start or end contains a thief
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        // 1. Multi-Source BFS to calculate thief distances
        vector<vector<int>> thief_dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    thief_dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : directions) {
                int newR = r + d[0];
                int newC = c + d[1];

                if (newR >= 0 && newR < n && newC >= 0 && newC < n && thief_dist[newR][newC] == -1) {
                    thief_dist[newR][newC] = thief_dist[r][c] + 1;
                    q.push({newR, newC});
                }
            }
        }

        // 2. Dijkstra's Algorithm using a Max-Heap
        // Stores: {safeness_factor, row, col}
        priority_queue<vector<int>> maxHeap; 
        vector<vector<int>> max_safeness(n, vector<int>(n, -1));

        maxHeap.push({thief_dist[0][0], 0, 0});
        max_safeness[0][0] = thief_dist[0][0];

        while (!maxHeap.empty()) {
            auto curr = maxHeap.top();
            maxHeap.pop();

            int curr_safe = curr[0];
            int r = curr[1];
            int c = curr[2];

            // If we reached the destination, this is our optimal maximum safeness factor
            if (r == n - 1 && c == n - 1) {
                return curr_safe;
            }

            for (auto& d : directions) {
                int newR = r + d[0];
                int newC = c + d[1];

                if (newR >= 0 && newR < n && newC >= 0 && newC < n) {
                    // The path safeness is limited by the bottleneck cell
                    int next_safe = min(curr_safe, thief_dist[newR][newC]);

                    // If we found a safer way to reach (newR, newC), update it
                    if (next_safe > max_safeness[newR][newC]) {
                        max_safeness[newR][newC] = next_safe;
                        maxHeap.push({next_safe, newR, newC});
                    }
                }
            }
        }

        return 0;
    }
};