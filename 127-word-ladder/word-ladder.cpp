class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string>st(wordList.begin(), wordList.end());  
        st.erase(beginWord);        

        queue<pair<string, int>>q;
        
        q.push({beginWord, 1});

        while (!q.empty()) {
            string s = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(s == endWord) return steps;

            for (int i = 0; i < s.size(); i++) {
                char original = s[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    s[i] = j;
                    if(st.find(s)!=st.end()){
                        q.push({s, steps+1});
                        st.erase(s);
                    }
                }
                s[i] = original;
            }
        }

        return 0;
    }
};