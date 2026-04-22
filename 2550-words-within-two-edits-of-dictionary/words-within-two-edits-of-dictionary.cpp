class Solution {
public:

    bool wordMatch(string word1, string word2){
        int count = 0;
         for(int i = 0; i<word1.size(); i++){
            if(word1[i]!=word2[i]){
                count++;
            }
            if(count>2) return false;
         }

        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int m = dictionary.size();

        vector<string>ans;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(wordMatch(queries[i], dictionary[j])){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }

        return ans;
    }
};