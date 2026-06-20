class Solution {
public:
    void setPath(vector<string>&ans){

    }
    vector<string> createGrid(int m, int n) {
        vector<string>ans;

        for(int i = 0; i<m-1; i++){
            string temp = "";
            for(int j = 0; j<n; j++){
                if(j == 0){
                    temp += '.';
                }else{
                    temp += '#';
                }
            }
            ans.push_back(temp);
        }

        //last row
        string temp = "";
        for(int i = 0; i<n; i++){
            temp += '.';
        }
        ans.push_back(temp);

        return ans;
    }
};