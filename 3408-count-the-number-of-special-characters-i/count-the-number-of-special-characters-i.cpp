class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int>smallMp;
        unordered_map<char, int>capMp;

        for(int i = 0; i<word.size(); i++){
            if(word[i]>='a' && word[i]<='z'){
                smallMp[word[i]]++;
            }else{
                capMp[word[i]]++;
            }
        }

        int count = 0;

        for(int i = 0; i<word.size(); i++){
            if(word[i]>='a' && word[i]<='z'){
                if(capMp.find(word[i]-32)!=capMp.end()){
                    count++;
                    smallMp.erase(word[i]);
                    capMp.erase(word[i]-32);
                }
            }
        }

        return count;
    }
};