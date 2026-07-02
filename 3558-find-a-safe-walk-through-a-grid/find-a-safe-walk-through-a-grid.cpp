class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // maxHealth[r][c] will store the maximum remaining health reached at (r, c)
        // Initialize all cells with -1 (unvisited/unreachable)
        vector<vector<int>> maxHealth(m, vector<int>(n, -1));

        // Priority Queue stores pairs of {remaining_health, {row, col}}
        // It automatically sorts so that the path with the HIGHEST health is checked first
        priority_queue<pair<int, pair<int, int>>> pq;

        // Calculate starting health after stepping onto (0, 0)
        int startHealth = health - grid[0][0];
        
        // If starting cell instantly kills us, we can't even begin
        if (startHealth <= 0) return false;

        maxHealth[0][0] = startHealth;
        pq.push({startHealth, {0, 0}});

        // Direction arrays for moving Down, Up, Right, Left
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();

            int currHealth = current.first;
            int r = current.second.first;
            int c = current.second.second;

            // If we reached the bottom-right corner with health > 0, we found a safe walk!
            if (r == m - 1 && c == n - 1) {
                return true;
            }

            // If we found a better path to this cell already, skip this older, worse path
            if (currHealth < maxHealth[r][c]) {
                continue;
            }

            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check grid boundaries
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nextHealth = currHealth - grid[nr][nc];

                    // If the next step keeps us alive AND gives more health than a previous path to (nr, nc)
                    if (nextHealth > 0 && nextHealth > maxHealth[nr][nc]) {
                        maxHealth[nr][nc] = nextHealth;
                        pq.push({nextHealth, {nr, nc}});
                    }
                }
            }
        }

        // If the queue becomes empty and we never reached the end, it's impossible
        return false;
    }
};