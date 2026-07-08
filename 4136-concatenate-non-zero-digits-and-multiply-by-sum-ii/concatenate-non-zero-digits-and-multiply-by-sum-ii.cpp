class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int m = s.size();

        vector<int> digits;
        vector<int> pos;

        for (int i = 0; i < m; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int n = digits.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> preSum(n + 1, 0);

        vector<long long> preNum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + digits[i];
            preNum[i + 1] = (preNum[i] * 10 + digits[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];


            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

            if (L == R) {
                ans.push_back(0);
                continue;
            }

            long long sum = preSum[R] - preSum[L];

            int len = R - L;

            long long x =
                (preNum[R] -
                 preNum[L] * pow10[len] % MOD +
                 MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};