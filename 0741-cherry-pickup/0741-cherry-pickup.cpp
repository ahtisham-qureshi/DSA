class Solution {
    int n;
    vector<vector<vector<int>>> dp;
public:
    int solve(int i,int j,int b,vector<vector<int>>& grid){
        int a = i + j - b;
        if(i>=n || j>=n || b>=n || a<0 || a>=n) return -1e9;
        if(i == n-1 && j == n-1 && b == n - 1 && a == n-1) return grid[i][j];
        if(dp[i][j][b] != -1)return dp[i][j][b];
        if(grid[i][j] == -1 || grid[a][b] == -1) return -1e9;

        int downDown = solve(i+1,j,b,grid);
        int downRight = solve(i+1,j,b+1,grid);
        int rightDown = solve(i,j+1,b,grid);
        int rightRight = solve(i,j+1,b+1,grid);

        int curr = (j == b && a == i)? grid[i][j] : (grid[i][j] + grid[a][b]);

        return dp[i][j][b] = curr + max({downDown,downRight,rightDown,rightRight});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(n,-1)));

        return max(0,solve(0,0,0,grid));
    }
};