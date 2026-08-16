class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        int zero = 0;
        int one = 0;
        int two = 0;
        for(int i = 0; i < n; i++){
            if(stones[i] % 3 == 0) zero++;
            else if(stones[i] % 3 == 1) one++;
            else two++;
        }
        if(zero % 2 == 0) return (one >=1 && two >= 1);
        else return abs(one - two) > 2;

    }
};