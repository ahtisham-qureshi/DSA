class Solution {
    vector<vector<vector<int>>> dp;
public:
    vector<int> solve(int i,int j,string& exp){
        if(!dp[i][j].empty()) return dp[i][j];

        bool isNumber = true;
        for (int k = i; k <= j; k++) {
            if (exp[k] == '+' || exp[k] == '-' || exp[k] == '*') {
                isNumber = false;
                break;
            }
        }

        if (isNumber) {
            int num = 0;
            for (int k = i; k <= j; k++)
                num = num * 10 + (exp[k] - '0');

            return dp[i][j] = {num};
        }

        for(int k = i;k<=j;k++){
            if (exp[k] == '+' || exp[k] == '-' || exp[k] == '*') {   
                auto left = solve(i,k-1,exp);
                auto right = solve(k+1,j,exp);

                for(auto l : left){
                    for(auto r : right){
                        if(exp[k] == '+'){
                            dp[i][j].push_back(l+r);
                        }else if(exp[k] == '-'){
                            dp[i][j].push_back(l-r);
                        }else{
                            dp[i][j].push_back(l*r);
                        }
                    }
                }
            }
        }

        return dp[i][j];
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.length();
        dp.assign(n,vector<vector<int>>(n));

        return solve(0,n-1,expression);
    }
};
