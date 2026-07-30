class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int m = 1;
        int press = 0;
        while(m <= n/8){
            press += m * 8;
            m++;
        }

        press += m * (n%8);

        return press;
    }
};