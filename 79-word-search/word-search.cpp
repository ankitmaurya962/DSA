class Solution {
public:
    bool dfs(vector<vector<char>>& board, int row, int col, int n, int m,
             vector<vector<int>>& vis, string word, int l, int k) {

        if (k == l - 1)
            return true;
        vis[row][col] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newRow = drow[i] + row;
            int newCol = dcol[i] + col;

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                vis[newRow][newCol] == 0 &&
                board[newRow][newCol] == word[k + 1]) {
                if (dfs(board, newRow, newCol, n, m, vis, word, l, k + 1))
                    return true;
            }
        }

        vis[row][col] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int l = word.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    if (dfs(board, i, j, n, m, vis, word, l, 0))
                        return true;
                }
            }
        }

        return false;
    }
};