class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        int n = s.length();
        vector<long long> dp(n+1,0);
        vector<long long>last(26,0);

        dp[0] = 1;

        for(int i = 1;i<=n;i++){
            int c = s[i-1] - 'a';

            dp[i] = (2*dp[i-1])%MOD;

            dp[i] = (dp[i] - last[c] + MOD)%MOD;

            last[c] = dp[i - 1];
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};