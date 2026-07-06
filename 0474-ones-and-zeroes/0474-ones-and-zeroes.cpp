class Solution {
    vector<vector<vector<int>>> dp;
    vector<pair<int,int>> cnt;
public:
    int solve(int i,int m,int n){
        if(i<0) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];

        int z = cnt[i].first, o = cnt[i].second;

        int skip = solve(i-1,m,n);
        int take = 0;
        if(m>=z && n>=o) take = 1 + solve(i-1,m-z,n-o);

        return dp[i][m][n] = max(skip,take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(auto &s : strs){
            int z = 0, o = 0;
            for(char c : s){
                if(c == '0') z++;
                else o++;
            }
            cnt.push_back({z,o});
        }

        return solve(strs.size() - 1,m,n);
    }
};