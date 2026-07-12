class Solution {
    vector<vector<int>> dp;
public:
    bool solve(int i,int j, string& s,string& p){
        if(i<0 && j<0) return 1;
        if(j<0) return 0;
        if(i<0){
            for(int k = j;k>=0;k--){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(i-1,j-1,s,p);
        }

        if(p[j] == '*'){
            return dp[i][j] = (solve(i-1,j,s,p) || solve(i,j-1,s,p));
        }

        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        dp.assign(m,vector<int>(n,-1));

        return solve(m-1,n-1,s,p);
    }
};
