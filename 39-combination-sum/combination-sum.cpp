class Solution {
public:
    void sum(int index, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& ans, int target){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            sum(index, candidates, ds, ans, target-candidates[index]);
            ds.pop_back();
        }
        sum(index+1, candidates, ds, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sum(0, candidates, ds, ans, target);
        return ans;
        
    }
};