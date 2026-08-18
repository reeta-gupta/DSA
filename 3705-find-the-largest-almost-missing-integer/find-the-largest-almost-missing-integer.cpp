class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            if(maxi < nums[i]) maxi = nums[i];
        }

        if(k == 1){
            int ans = INT_MIN;
            for (auto it: freq){
                if(it.second == 1){
                    ans = max(ans, it.first);
                }
            }
            return ans == INT_MIN ? -1 : ans;
        }
        else if(k == n){
            return maxi;
        }
        else{
            if(freq[nums[0]] > 1 && freq[nums[n-1]] > 1) return -1;
            if(freq[nums[n-1]] > 1){
                return nums[0];
            }
            else if(freq[nums[0]] == 1 && freq[nums[n-1]] == 1) return max(nums[0], nums[n-1]);
            else return nums[n-1];
        }
        
    }
};