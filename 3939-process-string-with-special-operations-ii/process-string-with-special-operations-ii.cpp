#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> lengths(n);
        long long curr = 0;
        const long long INF = 1e18;
        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                curr++;
            }
            else if(s[i] == '*'){
                if(curr > 0) curr--;
            }
            else if(s[i] == '#'){
                curr = min(INF, 2*curr);
            }
            lengths[i] = curr;
        }
        if(n == 0 || k >= lengths[n-1]) return '.';
        for(int i = n-1; i >= 0; i--){
            long long prevLen = (i == 0)? 0:lengths[i-1];
            if(s[i] >= 'a' && s[i] <= 'z'){
                if(k == prevLen) return s[i];
            }
            else if (s[i] == '#'){
                if(k >= prevLen) k-= prevLen;
            }
            else if(s[i] == '%'){
                if(prevLen > 0) k = prevLen -1-k;
            }
        }
         return '.';
        
    }     
};