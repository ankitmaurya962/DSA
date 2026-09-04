class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int shortest = INT_MAX;
        set<string>st;
        for(int i = 0; i<s.size(); i++){
            int count = 0;
            for(int j = i; j<s.size(); j++){
                if(s[j] == '1') count++;
                if(count == k) shortest = min(shortest, j-i+1); 
            }
        }
        if(shortest == INT_MAX) return "";
        
        for(int i = 0; i<=s.size()-shortest; i++){
            string temp = "";
            int count = 0;
            for(int j = i; j<i+shortest; j++){
                temp += s[j];
                if(s[j] == '1')count++;
            }

            if (count == k) st.insert(temp);
        }
        return st.empty() ? "" : *st.begin();
    }
};