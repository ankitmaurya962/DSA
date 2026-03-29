class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2) return true;
        for(int i = 0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                for(int j = i+1; j<s1.size(); j++){
                    if(s1[j] == s2[i] && j - i == 2){
                        swap(s1[i], s1[j]);
                    }

                    if(s1 == s2) return true;
                }
            }
        }
        return false;
    }
};