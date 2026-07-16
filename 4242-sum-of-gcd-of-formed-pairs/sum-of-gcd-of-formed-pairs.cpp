class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd(nums.size());
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            maxi = max(nums[i], maxi);
            prefixGcd[i] = gcd(maxi, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i = 0;
        int j = nums.size()-1;
        long long sum = 0;
        while(i < j){
            sum += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return sum;

    }
};