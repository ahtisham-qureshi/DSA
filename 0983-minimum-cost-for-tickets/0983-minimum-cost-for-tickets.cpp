class Solution {
    int n;
    unordered_set<int> s;
public:
    int solve(int i,vector<int>& dp,vector<int>& days, vector<int>& costs){
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];

        if(s.find(i) == s.end()) return dp[i] = solve(i+1,dp,days,costs);

        int day = costs[0] + solve(i+1,dp,days,costs);
        int week = costs[1] + solve(i+7,dp,days,costs);
        int month = costs[2] + solve(i+30,dp,days,costs);

        return dp[i] = min(day,min(week,month));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.back();
        for(auto i: days) s.insert(i);
        vector<int> dp(n+1,-1);

        return solve(1,dp,days,costs);
    }
};