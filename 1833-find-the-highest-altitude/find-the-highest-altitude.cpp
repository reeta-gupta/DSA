class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> alt(n+1);
        alt[0] = 0;
        int maxi = max(INT_MIN, alt[0]);
        for(int i = 0; i < n; i++){
            alt[i+1] = alt[i] + gain[i];
            maxi = max(maxi, alt[i+1]);
        }
        return maxi;
    }
};