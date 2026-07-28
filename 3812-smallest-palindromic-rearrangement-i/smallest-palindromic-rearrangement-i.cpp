class Solution {
public:
    string smallestPalindrome(string s) {
        int len = s.length();
        string left = s.substr(0, len/2);
        sort(left.begin(), left.end());
        string ans = left;
        if(len % 2 != 0){
            ans += s[len/2];
        }
        
        reverse(left.begin(), left.end());
        ans += left;
        return ans;

    }
};