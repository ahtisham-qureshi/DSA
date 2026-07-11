class Solution {
    vector<vector<long long>> dp;
public:
    long long solve(int i,int j,string& s, string& t){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = solve(i-1,j-1,s,t) + solve(i-1,j,s,t);
        }

        return dp[i][j] = solve(i-1,j,s,t);
    }
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        dp.assign(m,vector<long long>(n,-1));

        return (int)solve(m-1,n-1,s,t);
    }
};
