class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int len2 = word2.length();
        int len1 = word1.length();
        vector<int> ans(len2, -1);
        int j = len2-1;
        for(int i = len1-1; i >= 0; i--){
            if(j >= 0 && word1[i] == word2[j]){
                ans[j] = i;
                j-=1;
            }
        }

        vector<int> res;
         j = 0;
        int skip = 0;
        for(int i = 0; i < len1; i++){
            if(j == len2) break;
            if(word1[i] == word2[j] || (skip == 0 && (j == len2-1 || i < ans[j+1]))){
                skip += (word1[i] != word2[j])? 1 : 0;
                res.push_back(i);
                j += 1;
            }
        }
        return j == len2? res : vector<int>();
    }
};