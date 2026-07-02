class Solution {
public:
    int solve(int i,int j,vector<vector<char>>& mat,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(mat[i][j] == '0') return 0;
        if(dp[i][j] != -1) return dp[i][j];


        int up = solve(i-1,j,mat,dp);
        int left = solve(i,j-1,mat,dp);
        int topLeft = solve(i-1,j-1,mat,dp);

        return dp[i][j] = 1 + min(up,min(left,topLeft));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        int ans = 0;
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                ans = max(ans,solve(i,j,matrix,dp));
            }
        }

        return ans*ans;
    }
};
