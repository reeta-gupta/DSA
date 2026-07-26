class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int leftArr[n];
        leftArr[0] = 1;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                leftArr[i] = leftArr[i-1] + 1;
            }
            else{
                leftArr[i] = 1;
            }
        }
        int right = 1;
        int sum = max(leftArr[n-1], right);
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                right = right+1;
                
            }
            else{
                right = 1;
            }
            sum += max(leftArr[i], right);
        }
        return sum;
    }
};