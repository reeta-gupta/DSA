class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int ans = 0;
        vector<int> freq(10, 0);
        for(auto it: digits){
            freq[it]++;
        }

        for(int i = 0; i <= 8; i+= 2){
            if(freq[i] == 0) continue;
            freq[i]--;
            for(int j = 1; j <= 9; j++){
                if(freq[j] == 0) continue;
                freq[j]--;
                for(int k = 0; k <= 9; k++){
                    if(freq[k] == 0) continue;
                    ans++;
                }
                freq[j]++;
                
            }freq[i]++;
        }
        return ans;
    }
};