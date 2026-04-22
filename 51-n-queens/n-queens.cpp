class Solution {
public:

    bool isSafe(int row, int col, vector<string>&board, int n){
        int nrow = row;
        int ncol = col;

        //upper Diagonal
        while(nrow >=0 && ncol>=0){
            if(board[nrow][ncol] == 'Q') return false;
            nrow--;
            ncol--;
        }

        //same row
        nrow = row;
        ncol = col;
        while(ncol>=0){
            if(board[nrow][ncol] == 'Q') return false;
            ncol--;
        }

        //lower Diagonal
        nrow = row;
        ncol = col;
        while(nrow < n && ncol>=0){
            if(board[nrow][ncol] == 'Q') return false;
            nrow++;
            ncol--;
        }

        return true;
    }
    void func(vector<string>&board, vector<vector<string>>&ans, int col, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0; i<n; i++){
            if(isSafe(i, col, board, n)){
                board[i][col] = 'Q';
                func(board, ans, col+1, n);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n, '.'); 
        vector<string>board(n, s);

        func(board, ans, 0, n);

        return ans;
    }
};