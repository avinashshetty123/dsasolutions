class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';
        dfs(r - 1, c, grid);
        dfs(r, c - 1, grid);
        dfs(r + 1, c, grid);
        dfs(r, c + 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int island = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    dfs(i, j, grid);
                }
            }
        }
        return island;
    }
};