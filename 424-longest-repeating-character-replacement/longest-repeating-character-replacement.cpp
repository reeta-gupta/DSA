class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int l = 0;
        int maxF = 0;
        int maxLen = 0;

        for (int r = 0; r < s.size(); r++) {

            freq[s[r] - 'A']++;

  
            maxF = max(maxF, freq[s[r] - 'A']);

 
            while ((r - l + 1) - maxF > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};