class Solution {
public:
    string processStr(string s) {
        string res = "";
        int i = 0;
        while(i < s.length()){
            if(s[i] >= 'a' && s[i] <= 'z'){
                res.push_back(s[i]);
            }
            else if(s[i] == '*'){
                if(res.length() != 0){
                    res.pop_back();
                }
            }
            else if(s[i] == '#'){
                res = res + res;
            }
            else{
                reverse(res.begin(),res.end());
            }
            i++;
        }
        return res;
    }
};