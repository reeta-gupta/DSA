class Solution {
public:
    // int solve(int i, int j, vector<int>& piles){
    //     if(i > j) return false;
    //     if(i == j) return piles[i];

    //     int take_i = piles[i] + min(solve(i+2, j, piles), solve(i+1, j-1, piles));
    //     int take_j = piles[j] + min(solve(i+1, j-1, piles), solve(i, j-2, piles));

    //     return max(take_i, take_j);
    // }
    bool stoneGame(vector<int>& piles) {
        // int n = piles.size();
        // int sum = 0;
        // for(int i = 0; i < n; i++){
        //     sum += piles[i];
        // }

        // int aliceScore = solve(0, n-1, piles);
        // int bobScore = sum - aliceScore;
        // return aliceScore > bobScore;
        return true;
    }
};