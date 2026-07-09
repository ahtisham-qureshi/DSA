class Solution {
    vector<vector<int>> dp;
    int n;
public:
    int solve(int i,int j,string& s){
         if (i >= j)
            return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]){
            return dp[i][j] = solve(i+1,j-1,s);
        }else{
            return dp[i][j] = 1 + min(solve(i+1,j,s),solve(i,j-1,s));
        }
    }
    int minInsertions(string s) {
        n = s.length();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,n-1,s);
    }
};
