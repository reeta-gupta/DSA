class Solution {
public:
    int maximumLengthSubstring(string s) {
        int len = s.length();
        int l = 0;
        int maxLen = 0;
        unordered_map<char, int> freq;
        for(int r = 0; r < len; r++){
            freq[s[r]]++;
            while(freq[s[r]] > 2){
                freq[s[l]]--;
                l = l+1;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};