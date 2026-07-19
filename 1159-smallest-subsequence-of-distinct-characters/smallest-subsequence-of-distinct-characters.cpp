class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        for(char ch : s)
            freq[ch - 'a']++;

        string res = "";

        for(char ch : s)
        {
            freq[ch - 'a']--;

            if(used[ch - 'a'])
                continue;

            while(!res.empty() &&
                  res.back() > ch &&
                  freq[res.back() - 'a'] > 0)
            {
                used[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(ch);
            used[ch - 'a'] = true;
        }

        return res;
    }
};