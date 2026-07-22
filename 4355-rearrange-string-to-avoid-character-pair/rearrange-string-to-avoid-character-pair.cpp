class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int x_count = 0;
        int y_count = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == x){
                x_count++;
            }else if(s[i] == y){
                y_count++;
            }
        }
        string temp = "";
        for(int i = 0; i<y_count; i++){
            temp += y;
        }
        for(int i = 0; i<x_count; i++){
            temp += x;
        }
    
        for(int i = 0; i<s.size(); i++){
            if(s[i]!= x && s[i]!=y){
                temp += s[i];
            }
        }

        return temp;
    }
};