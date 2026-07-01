class Solution {
    int n;
    unordered_set<int> s;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.back();
        for(auto i: days) s.insert(i);
        vector<int> dp(n+31,0);


        for(int i = n;i>0;i--){
            if(s.find(i) == s.end()){
                dp[i] = dp[i+1];
                continue;
            }

            int day = costs[0] + dp[i+1];
            int week = costs[1] + dp[i+7];
            int month = costs[2] + dp[i+30];

            dp[i] = min(day,min(week,month));
        }

        return dp[1];
    }
};
