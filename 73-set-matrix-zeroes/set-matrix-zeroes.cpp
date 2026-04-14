class Solution {
public:
void setrow(vector<vector<int>>&matrix,int i){
  for (int j = 0; j < matrix[i].size(); j++)
  {
    if (matrix[i][j]!=0)
    {
      matrix[i][j] = 0;
    }
  }
}

void setcolumn(vector<vector<int>>&matrix,int j){
  for (int i = 0; i < matrix.size(); i++)
  {
    if (matrix[i][j]!=0)
    {
      matrix[i][j] = 0;
    }
  }
}
void setZeroes(vector<vector<int>>& matrix) {

   stack<pair<int, int>>stk;
   for (int i = 0; i < matrix.size(); i++)
   {
    for (int j = 0; j < matrix[i].size(); j++)
    {
      if (matrix[i][j]==0)
      {
        stk.push({i, j});
      }
    }
  }  

  while(!stk.empty()){
    auto coord = stk.top();
    stk.pop();

    setrow(matrix, coord.first);
    setcolumn(matrix, coord.second);
  }
}
};
