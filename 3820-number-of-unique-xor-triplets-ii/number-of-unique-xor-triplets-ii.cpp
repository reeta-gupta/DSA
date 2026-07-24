class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> pair;
        unordered_set<int> ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                pair.insert(nums[i]^nums[j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int x : pair){
                ans.insert(x ^ nums[i]);
            }
        }
        return ans.size();
    }
};