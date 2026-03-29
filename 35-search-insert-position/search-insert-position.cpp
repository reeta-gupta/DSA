class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int ans = nums.size();
        int j = nums.size()-1;
        int mid = i + (j-i)/2;
        while(i <= j){
            if(nums[mid] >= target){
                ans = mid;
                j = mid-1;
            }
            else{
                i = mid+1;
            }
            mid = i + (j-i)/2;
        }
        return ans;
    }
};