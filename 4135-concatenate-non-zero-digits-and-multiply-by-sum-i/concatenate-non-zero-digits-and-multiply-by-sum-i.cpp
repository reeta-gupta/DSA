class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        int sum = 0;
        long long x = 0;
        for(char ch : s){
            int digit = ch - '0';
            if(digit != 0){
                x = x*10+digit;
                sum += digit;
            }
        }
        return sum*x;
        
    }
};