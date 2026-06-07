class Solution {
public:
    string to_binary(int n) {
        if (n == 0)
            return "0";

        string s = "";

        while (n > 0) {
            s += (n % 2) + '0';
            n /= 2;
        }

        reverse(s.begin(), s.end());
        return s;
    }
    bool consecutiveSetBits(int n) {
        string binary = to_binary(n);
        int count = 0;
        for (int i = 1; i < binary.size(); i++) {
            if (binary[i] == '1' && binary[i-1] == '1') {
                count++;
            }
        }

        return count == 1 ? true : false;
    }
};