class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for(char ch : s) {
            freq[ch - 'a']++;
        }

        int n = target.size();

        for(int i = 0; i < n; i++) {

            int cur = target[i] - 'a';

            if(freq[cur] > 0) {
                freq[cur]--;
                continue;
            }

            for(int k = cur + 1; k < 26; k++) {

                if(freq[k] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + k);

                    freq[k]--;

                    for(int x = 0; x < 26; x++) {
                        while(freq[x] > 0) {
                            ans += char('a' + x);
                            freq[x]--;
                        }
                    }

                    return ans;
                }
            }
            for(int j = i - 1; j >= 0; j--) {

                freq[target[j] - 'a']++;

                int cur = target[j] - 'a';

                for(int k = cur + 1; k < 26; k++) {

                    if(freq[k] > 0) {

                        string ans = target.substr(0, j);

                        ans += char('a' + k);

                        freq[k]--;

                        for(int x = 0; x < 26; x++) {
                            while(freq[x] > 0) {
                                ans += char('a' + x);
                                freq[x]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }
        for(int j = n - 1; j >= 0; j--) {

            freq[target[j] - 'a']++;

            int cur = target[j] - 'a';
            for(int k = cur + 1; k < 26; k++) {

                if(freq[k] > 0) {

                    string ans = target.substr(0, j);

                    ans += char('a' + k);

                    freq[k]--;

                    for(int x = 0; x < 26; x++) {
                        while(freq[x] > 0) {
                            ans += char('a' + x);
                            freq[x]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};