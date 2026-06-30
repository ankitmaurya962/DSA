class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count=0;
        vector<int> prevseen(3, -1);
        for(int i=0; i<n; i++){
            prevseen[s[i]-'a']=i;
    
            if(prevseen[0]!=-1 && prevseen[1]!=-1 && prevseen[2]!=-1){
                count=count+(1+min({prevseen[0], prevseen[1], prevseen[2]}));
            }
        }
        return count;
    }
};