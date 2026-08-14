class Solution {
public:
    bool dfs(vector<vector<char>>& board, int r, int c, string word, int i) {
        if (i == word.length()) {
            return true;
        }
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() ||
            board[r][c] != word[i]) {
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board, r + 1, c, word, i + 1) ||
                     dfs(board, r - 1, c, word, i + 1) ||
                     dfs(board, r, c + 1, word, i + 1) ||
                     dfs(board, r, c - 1, word, i + 1);
        board[r][c] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};