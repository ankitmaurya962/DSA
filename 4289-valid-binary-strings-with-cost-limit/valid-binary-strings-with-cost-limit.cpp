class Solution {
public:
    string to_binary(int num, int n){
        string binary(n, '0');

        for(int i = n - 1; i >= 0; i--){
            binary[i] = (num % 2) + '0';
            num /= 2;
        }

        return binary;
    }

    bool isValid(string &binary){
    for(int i = 1; i < binary.size(); i++){
        if(binary[i] == '1' && binary[i-1] == '1'){
            return false;
        }
    }
    return true;
}

    int costCal(string &binary){
        int cost = 0;

        for(int i = 0; i < binary.size(); i++){
            if(binary[i] == '1'){
                cost += i;
            }
        }

        return cost;
    }

    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;

        for(int i = 0; i < (1 << n); i++){
            string binary = to_binary(i, n);

            if(isValid(binary) && costCal(binary) <= k){
                ans.push_back(binary);
            }
        }

        return ans;
    }
};