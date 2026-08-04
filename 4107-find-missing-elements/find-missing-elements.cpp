class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> st;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int num : nums){
            mini = min(num, mini);
            maxi = max(num, maxi);
            st.insert(num);
        }

        for(int i = mini; i <= maxi; i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
        return ans;

    }
};