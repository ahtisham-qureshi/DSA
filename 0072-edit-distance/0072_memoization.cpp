class Solution {
    vector<vector<int>> dp;
public:
    int solve(int i, int j ,string& s, string& t){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = solve(i-1,j-1,s,t);
        }

        return dp[i][j] = 1 + min({solve(i-1,j-1,s,t),solve(i-1,j,s,t),solve(i,j-1,s,t)});
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        dp.assign(m,vector<int>(n,-1));

        return solve(m-1,n-1,word1,word2);
    }
};
