class Solution {
public:
    void sum(int index, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans){
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            sum(i+1,candidates, target-candidates[i], ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        sum(0,candidates, target, ds, ans);
        return ans;
    }
};