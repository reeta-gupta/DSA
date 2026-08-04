class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int idx = 0;
        for(int x = nums[0]; x <= nums[n-1]; x++){
            if(idx < n && nums[idx] == x){
                idx++;
            }
            else{
                ans.push_back(x);
            }
        }
        return ans;

    }
};