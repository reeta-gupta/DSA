#include<bits/stdc++.h>
class Solution {
public:
    // static bool comp(int a, int b){
    //     return abs(a) < abs(b);
    // }
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        sort(nums.begin(), nums.end());
        maxi = max((nums[0] * nums[1] * nums[n-1]), (nums[n-1] * nums[n-2] * nums[n-3]));
        return maxi;
        
    }
};