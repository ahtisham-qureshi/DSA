class Solution {
    int n;
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp,vector<vector<bool>>& vis){
        if(i == n - 1) return grid[i][j];
        if(vis[i][j]) return dp[i][j];
        
        vis[i][j] = true;
        int ans = 1e9;
        for(int k = 0;k<n;k++){
            if(k == j) continue;
            ans = min(ans,solve(i+1,k,grid,dp,vis));
        }

        return dp[i][j] = grid[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n));
        vector<vector<bool>> vis(n,vector<bool>(n,false));

        int ans = 1e9;
        for(int i = 0;i<n;i++){
            ans = min(ans,solve(0,i,grid,dp,vis));
        }

        return ans;
    }
};
