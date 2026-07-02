class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n));

        for(int i = 0;i<n;i++){
            dp[n-1][i] = grid[n-1][i];
        }

        for(int i = n - 2;i>=0;i--){
            for(int j = 0;j<n;j++){
                int temp = 1e9;
                for(int k = 0;k<n;k++){
                    if(k == j) continue;
                    temp = min(temp,dp[i+1][k]);
                }
                dp[i][j] = grid[i][j] + temp;
            }
        }

        int ans = 1e9;
        for(int i = 0;i<n;i++) {
            ans = min(ans,dp[0][i]);
        }

        return ans;
    }
};
