class Solution {
    vector<unsigned long long> dp;
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        dp.assign(n+1,0);

        dp[0] = 1; 

        for(int i = 1;i<=m;i++){
            vector<unsigned long long> curr(n+1,0);
            curr[0] = 1;
            for(int j = 1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = dp[j-1] + dp[j];
                }else{
                    curr[j] = dp[j];
                }
            }
            dp = curr;
        }

        return (int)dp[n];
    }
};
