class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        bool allZero = true;
        for(int r = 0; r < n; r++){
            xorr = xorr^nums[r];

            if(nums[r] != 0){
                allZero = false;
            }
        }
        if(allZero) return 0;

        if(xorr == 0) return n-1;
        
        return n;
    }
};