class Solution {
public:
    int countWaviness(string s){
        int n = s.size();
        int count = 0;
        if(n<3){
            return 0;
        }
        for(int i = 1; i<n-1; i++){
            if(s[i-1]>s[i] && s[i+1]>s[i]){
                count+=1;
            }else if(s[i-1]<s[i] && s[i+1]<s[i]){
                count+=1;
            }
        }

        return count;
    }
    int totalWaviness(int num1, int num2) {    
        int waviness = 0;
        for(int i = num1; i<=num2; i++){
            string s1 = to_string(i);
            waviness += countWaviness(s1);
        }

        return waviness;
    }
};