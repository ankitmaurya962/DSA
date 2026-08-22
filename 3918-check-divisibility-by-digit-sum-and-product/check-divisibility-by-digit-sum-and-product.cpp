class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int s = 0;
        int m = 1;
        while(temp!=0){
            int digit = temp%10;
            s += digit;
            m *= digit;

            temp /=10;
        }

        if(n%(s + m) == 0) return true;

        return false;
    }
};