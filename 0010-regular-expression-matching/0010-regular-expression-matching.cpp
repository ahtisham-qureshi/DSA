class Solution {
    vector<vector<int>> dp;
public:
    int solve(int i, int j,string& s, string& p){
        if(i<0 && j<0) return 1;
        if(j<0) return 0;
        if(i<0 ){
            for(int k = j;k>=0;k =k-2){
                if(p[k] != '*') return false;
            }
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '.' ){
            return dp[i][j] = solve(i-1,j-1,s,p);
        }

        if(p[j] == '*'){
            int math = false;
            if(p[j-1] == s[i] || p[j-1] == '.'){
                math = solve(i-1,j,s,p);
            }
            return dp[i][j] = solve(i,j-2,s,p) || math;
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        dp.assign(m,vector<int>(n,-1));

        return solve(m-1,n-1,s,p);
    }
};