class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++){
            freq[word[i] - 'a']++;
        }
        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) break;
            ans += (i/8+1)* freq[i];
            
        }
        return ans;
    }
};