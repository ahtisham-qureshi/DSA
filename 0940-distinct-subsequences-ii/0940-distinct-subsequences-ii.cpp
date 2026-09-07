class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        int n = s.length();
        vector<long long>last(26,0);

        long long prev = 1;

        for(int i = 1;i<=n;i++){
            int c = s[i-1] - 'a';

            long long curr = (2*prev)%MOD;

            curr = (curr - last[c] + MOD)%MOD;

            last[c] = prev;
            prev = curr;
        }

        return (prev - 1 + MOD) % MOD;
    }
};