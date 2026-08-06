class Solution {
public:
    int smallestNumber(int n, int t) {
        int pdt;
        for(int i = n; i < n+10; i++){
            pdt = 1;
            int x = i;
            while(x != 0){
                int digit = x % 10;
                pdt = pdt*digit;
                x = x/10;
            }
            if(pdt % t == 0){
                return i;
            }
        } 
        return -1;
    }
};