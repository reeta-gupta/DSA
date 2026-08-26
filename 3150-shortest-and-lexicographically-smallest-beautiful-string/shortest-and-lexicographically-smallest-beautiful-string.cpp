class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int maxlen = 0;
        int len = INT_MAX;
        int r= 0;
        int l = 0;
        int ones = 0;
        string ans = "";
        int n = s.length();
        for(int r = 0; r < n; r++){
            if(s[r] == '1'){
                ones++;
            }
            while(ones > k){
                if(s[l] == '1'){
                    ones--;
                }
                l++;
            }
            if(ones == k){
                while(s[l] == '0'){
                    l++;
                }
                int currLen = r-l+1;
                if(currLen < len){
                    len = currLen;
                    ans = s.substr(l, currLen);
                }
                else if(currLen == len && s.substr(l, currLen) < ans) {
                    ans = s.substr(l, currLen);
                }
            }
        }
        return ans;

    }
};