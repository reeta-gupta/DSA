class Solution {
public:
    void sum(int index, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans){
        if(index == candidates.size()){
            if(target == 0) ans.push_back(ds);
            return;
        }
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            sum(index, candidates, target-candidates[index], ds, ans);
            ds.pop_back();
        }
        sum(index+1, candidates, target, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        sort(candidates.begin(), candidates.end());
        sum(0,candidates, target, ds, ans);
        return ans;
    }
};