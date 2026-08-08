class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> nextPos(m, -1);

        int j = m - 1;

        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                nextPos[j] = i;
                j--;
            }
        }

        vector<int> result;
        j = 0;
        bool changed = false;

        for (int i = 0; i < n && j < m; i++) {

            if (word1[i] == word2[j]) {
                result.push_back(i);
                j++;
            }

            else if (!changed) {
                if (j == m - 1) {
                    result.push_back(i);
                    changed = true;
                    j++;
                }

                else if (nextPos[j + 1] != -1 &&
                         i < nextPos[j + 1]) {

                    result.push_back(i);
                    changed = true;
                    j++;
                }
            }
        }

        if (j == m)
            return result;

        return {};
    }
};