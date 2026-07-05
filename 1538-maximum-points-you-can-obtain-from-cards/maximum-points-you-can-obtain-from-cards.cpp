class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = 0;
        int leftSum = 0;
        int rightSum = 0;
        for(int i = 0; i < k; i++){
            leftSum += cardPoints[i];
        }
        maxSum = leftSum;
        int r = cardPoints.size()-1;
        for(int  i = k-1; i >= 0; i--){
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[r];
            maxSum = max(maxSum, leftSum + rightSum);
            r--;
        }
        return maxSum;
    }
};