class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);

        for(char ch : s){
            freq[ch - 'a']++;
        }
        string res = "";

        for(char ch : s){
            freq[ch-'a']--;

            if(visited[ch-'a'])
                continue;
            
            while(!res.empty() && res.back() > ch && freq[res.back()- 'a'] > 0){
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return res;
    }
};