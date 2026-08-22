class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pdt = 1;
        int temp = n;
        while(n != 0){
            int digit = n%10;
            sum += digit;
            pdt *= digit;
            n = n/10;
        }
        int ans = sum + pdt;
        if(temp % (ans) == 0) return true;
        else return false;
    }
};