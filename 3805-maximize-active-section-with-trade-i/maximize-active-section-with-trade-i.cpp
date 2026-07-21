class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int countOnes = 0;
        int n = s.length();
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1') countOnes++;
        }
        string augumented = "";
        augumented = "1" + s + "1";
        vector<pair<char,int>> freq;
        
        int i = 0;
        while(i < augumented.length()){
            char ch = augumented[i];
            int cnt = 0;
            while(i < augumented.length() && ch == augumented[i]){
                cnt++;
                i++;
            }
            freq.push_back({ch, cnt});
        }
        int ans = countOnes;
        for(int i = 1; i < freq.size()-1; i++){
            if(freq[i].first == '1' && freq[i-1].first == '0' && freq[i+1].first == '0'){
                int leftZeroes = freq[i-1].second;
                int rightZeroes = freq[i+1].second;
                ans = max(ans, countOnes + leftZeroes + rightZeroes);

            }
        }
        return min(ans, n);

    }
};