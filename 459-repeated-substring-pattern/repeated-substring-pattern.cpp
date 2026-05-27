class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n == 1) return false;
        string temp = "";
        for(int i = 0; i<n/2; i++){
            temp+=s[i];
            int m = temp.size();
            
            int required = n/m;
            string newtemp = "";
            for (int i = 0; i < required; i++) {
                newtemp += temp; 
            }
            if(s == newtemp) return true;
        }
        return false;
    }
};