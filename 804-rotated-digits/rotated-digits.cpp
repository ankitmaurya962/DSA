class Solution {
public:
    bool checkGood(int no){
        int temp = no;
        int count = 0;

        while(temp!=0){
            int last = temp%10;
            if(last == 3 || last == 7 || last == 4) return false;
            else if(last == 2 || last == 5 || last == 6 || last == 9) count++;
            temp = temp/10;
        }
        return count?true: false;
    }
    int rotatedDigits(int n) {

        int count = 0;
        for(int i = 1; i<=n; i++){
            if(checkGood(i)){
                count++;
            }
        }

        return count;
    }
};