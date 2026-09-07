class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        vector<int> lastPos(26, -1);

        dp[n] = 0; 

        for (int i = n - 1; i >= 0; --i) {
            char ch = s[i];
            int idx = ch - 'a';

            dp[i] = (2LL * dp[i + 1] + 1) % MOD;

            if (lastPos[idx] != -1) {
                dp[i] = (dp[i] - dp[lastPos[idx] + 1] - 1 + MOD) % MOD;
            }

            lastPos[idx] = i;
        }

        return (dp[0] + MOD) % MOD;
    }
};