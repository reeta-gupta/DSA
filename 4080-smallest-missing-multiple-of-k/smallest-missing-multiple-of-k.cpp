class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        int multiple = k;
        while(st.find(multiple) != st.end()){
            multiple += k;
        }
        return multiple;
    }
};