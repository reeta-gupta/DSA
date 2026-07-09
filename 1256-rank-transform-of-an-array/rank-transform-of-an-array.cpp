class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp;
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(), temp.end());
        int rank = 1;
        for(int i = 0; i < temp.size(); i++){
            if(mp.find(temp[i]) == mp.end()){
                mp[temp[i]] = rank;
                rank++;
            }
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};