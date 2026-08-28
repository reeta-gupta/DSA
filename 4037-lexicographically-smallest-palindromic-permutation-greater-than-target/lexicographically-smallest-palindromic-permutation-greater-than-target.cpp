class Solution {
public:

    // Build palindrome from left half and middle
    string makePalindrome(string left, char mid, int n) {
        string result = left;

        if(n % 2 == 1)
            result += mid;

        for(int i = left.length() - 1; i >= 0; i--) {
            result += left[i];
        }

        return result;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.length();

        // -----------------------------
        // 1. Frequency of characters
        // -----------------------------
        vector<int> freq(26, 0);

        for(char ch : s) {
            freq[ch - 'a']++;
        }

        // -----------------------------
        // 2. Check if palindrome possible
        // -----------------------------
        int odd = 0;

        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 != 0)
                odd++;
        }

        if(odd > 1)
            return "";

        // -----------------------------
        // 3. Find middle character
        // -----------------------------
        char mid = '\0';

        for(int i = 0; i < 26; i++) {

            if(freq[i] % 2 != 0) {
                mid = char('a' + i);
                freq[i]--;
                break;
            }
        }

        // -----------------------------
        // 4. Frequencies for LEFT HALF
        // -----------------------------
        for(int i = 0; i < 26; i++) {
            freq[i] /= 2;
        }

        int halfLen = n / 2;

        string left = "";

        // =====================================================
        // 5. Try to construct left half equal to target's half
        // =====================================================

        for(int i = 0; i < halfLen; i++) {

            int curr = target[i] - 'a';

            // -----------------------------------------
            // We can keep target[i]
            // -----------------------------------------
            if(freq[curr] > 0) {

                freq[curr]--;
                left += target[i];
            }

            // -----------------------------------------
            // We cannot keep target[i]
            // -----------------------------------------
            else {

                // First try making it GREATER at this position
                for(int k = curr + 1; k < 26; k++) {

                    if(freq[k] > 0) {

                        string ans = left;

                        ans += char('a' + k);

                        freq[k]--;

                        // Fill remaining left half
                        for(int x = 0; x < 26; x++) {
                            while(freq[x] > 0) {
                                ans += char('a' + x);
                                freq[x]--;
                            }
                        }

                        return makePalindrome(ans, mid, n);
                    }
                }

                // -----------------------------------------
                // Cannot make it greater here.
                // Backtrack.
                // -----------------------------------------
                for(int j = i - 1; j >= 0; j--) {

                    // Restore character used at j
                    freq[target[j] - 'a']++;

                    int prev = target[j] - 'a';

                    // Try smallest character > target[j]
                    for(int k = prev + 1; k < 26; k++) {

                        if(freq[k] > 0) {

                            string ans = target.substr(0, j);

                            ans += char('a' + k);

                            freq[k]--;

                            // Fill remaining half in sorted order
                            for(int x = 0; x < 26; x++) {
                                while(freq[x] > 0) {
                                    ans += char('a' + x);
                                    freq[x]--;
                                }
                            }

                            return makePalindrome(ans, mid, n);
                        }
                    }
                }

                return "";
            }
        }

        // =====================================================
        // 6. Entire LEFT HALF matched target
        // =====================================================

        // If n is odd, first compare the middle character
        if(n % 2 == 1) {

            int targetMid = target[halfLen] - 'a';
            int actualMid = mid - 'a';

            // Middle is greater
            if(actualMid > targetMid) {
                return makePalindrome(left, mid, n);
            }

            // Middle is smaller:
            // we MUST backtrack the left half
            if(actualMid < targetMid) {
                // directly go to backtracking below
            }

            // Middle is equal:
            // Need to compare the forced right half with target.
            if(actualMid == targetMid) {

                string current = makePalindrome(left, mid, n);

                if(current > target)
                    return current;
            }
        }
        else {

            // Even length:
            // left is equal, so compare the whole palindrome
            string current = makePalindrome(left, mid, n);

            if(current > target)
                return current;
        }

        // =====================================================
        // 7. Backtrack LEFT HALF
        // =====================================================

        for(int j = halfLen - 1; j >= 0; j--) {

            // Restore target[j]
            freq[target[j] - 'a']++;

            int prev = target[j] - 'a';

            // Find smallest character greater than target[j]
            for(int k = prev + 1; k < 26; k++) {

                if(freq[k] > 0) {

                    string ans = target.substr(0, j);

                    ans += char('a' + k);

                    freq[k]--;

                    // Fill remaining left half
                    for(int x = 0; x < 26; x++) {

                        while(freq[x] > 0) {
                            ans += char('a' + x);
                            freq[x]--;
                        }
                    }

                    return makePalindrome(ans, mid, n);
                }
            }
        }

        return "";
    }
};