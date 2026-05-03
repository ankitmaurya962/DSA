class Solution {
  public:
   void func(vector<string>& ans, string temp, int row, int col, int n, int m, vector<vector<int>>&vis, vector<vector<int>>&maze){
       if(row == n-1 && col == m-1){
           ans.push_back(temp);
           return;
       }
       
       int drow[] = {1, 0, 0, -1};
       int dcol[] = {0, -1, 1, 0};
       string dir = "DLRU";
       for(int i = 0; i<4; i++){
           int newRow = row + drow[i];
           int newCol = col + dcol[i];
           
           if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && vis[newRow][newCol]!=1 && maze[newRow][newCol] == 1){
               vis[newRow][newCol] = 1;
               temp.push_back(dir[i]);
               func(ans, temp, newRow, newCol, n, m, vis, maze);
               vis[newRow][newCol] = 0;
               temp.pop_back();
           }
       }
   }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>ans;
        int n = maze.size();
        int m = maze[0].size();
        string temp ="";
        vector<vector<int>>vis(n ,vector<int>(m, 0));
        vis[0][0] = 1;
        func(ans, temp, 0, 0, n ,m, vis, maze);
        
        return ans;
    }
};