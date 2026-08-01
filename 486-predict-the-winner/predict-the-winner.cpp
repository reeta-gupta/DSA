class Solution {
public:
    int solve(int i, int j, vector<int>& nums){
        if(i == j) return nums[i];
        if(i > j) return false;

        int take_i = nums[i] + min(solve(i+2, j, nums), solve(i+1, j-1, nums));
        int take_j = nums[j] + min(solve(i+1, j-1, nums), solve(i, j-2, nums));

        return max(take_i, take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        int player1_score = solve(0, n-1, nums);
        int player2_score = sum - player1_score;
        return player1_score >= player2_score;

    }
};