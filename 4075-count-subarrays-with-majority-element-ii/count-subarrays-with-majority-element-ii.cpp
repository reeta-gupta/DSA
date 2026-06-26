class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        long long ans = 0;
        long long validLeftPoints = 0;
        int cumSum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                validLeftPoints += mp[cumSum];
                cumSum++;
            }
            else{
                cumSum--;
                validLeftPoints -= mp[cumSum];
            }
            mp[cumSum]++;
            ans += validLeftPoints;
        }
        return ans;
    }
};