class Solution {
public:
    void func(vector<string>&board, vector<vector<string>>&ans, int col, int n, vector<int>&row, vector<int>&upperDiagnol, vector<int>&lowerDiagnol){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0; i<n; i++){
            if(!upperDiagnol[i+col] && !lowerDiagnol[n-1 +(col-i)] && !row[i]){
                upperDiagnol[i+col] = 1;
                lowerDiagnol[n-1 + (col - i)] = 1;
                row[i] = 1;
                board[i][col] = 'Q';
                func(board, ans, col+1, n, row, upperDiagnol, lowerDiagnol);
                board[i][col] = '.';
                upperDiagnol[i+col] = 0;
                lowerDiagnol[n-1 + (col - i)] = 0;
                row[i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n, '.'); 
        vector<string>board(n, s);
        vector<int>row(n, 0);
        vector<int>upperDiagnol(2*n-1, 0);
        vector<int>lowerDiagnol(2*n-1, 0);

        func(board, ans, 0, n, row, upperDiagnol, lowerDiagnol);

        return ans;
    }
};