class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int sum = 0;

        string ans ="";
        for(int i = 0; i<words.size(); i++){
            for(int j = 0; j<words[i].size(); j++){
                sum += weights[words[i][j]-'a'];
            }
            ans += ('z' - sum%26);
            sum=0;
        }

        return ans;
    }
};