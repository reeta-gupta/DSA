class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int i = 0;
        int ans = -1;
        int j = nums.size()-1;
        int mid = i + (j-i)/2;
        while(i <= j){
            if(nums[mid] == target){
                ans = mid;
                j = mid-1;
            }else if(nums[mid] > target){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
            mid = i + (j-i)/2;
        }
        return ans;
    }

    int lastOcc(vector<int>& nums, int target){
        int i = 0;
        int ans = -1;
        int j = nums.size()-1;
        int mid = i + (j-i)/2;
        while(i <= j){
            if(nums[mid] == target){
                ans = mid;
                i = mid+1;
            }
            else if(nums[mid] < target){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
            mid = i + (j-i)/2;
        }
        return ans;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> temp;
        temp.push_back(firstOcc(nums,target));
        temp.push_back(lastOcc(nums,target));
        return temp;

    }
};