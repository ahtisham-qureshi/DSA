class Solution {
    vector<int> dp;
    int n;

    bool isPalindrome(int i,int j,string& s){
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
public:
    int solve(int i,string& s){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int best = 1e9;
        for(int j = i;j<n;j++){
            if(isPalindrome(i,j,s)){
                best = min(best, 1 + solve(j+1,s));
            }
        }


        return dp[i] = best;
    }
    int minCut(string s) {
        n = s.length();
        dp.assign(n,-1);

        return solve(0,s)-1;
    }
};
