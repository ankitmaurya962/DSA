class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        long long sum = 0;

        string nonZeroNum = "";
        while(n!=0){
            int digit = n%10;
            if(digit!=0){
                nonZeroNum += to_string(digit);
            }
            sum += digit;
            n = n/10;
        }

        reverse(nonZeroNum.begin(), nonZeroNum.end());

        long long nonZero = stoi(nonZeroNum);

        return nonZero * sum;
    }
};