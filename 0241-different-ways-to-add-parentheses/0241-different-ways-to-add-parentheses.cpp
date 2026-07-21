class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        int n = exp.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
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

                    dp[i][j] = {num};
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (!dp[i][j].empty())
                    continue;
                    
                for (int k = i; k <= j; k++) {
                    if (exp[k] == '+' || exp[k] == '-' || exp[k] == '*') {
                        auto left = dp[i][k - 1];
                        auto right = dp[k + 1][j];

                        for (auto l : left) {
                            for (auto r : right) {
                                if (exp[k] == '+') {
                                    dp[i][j].push_back(l + r);
                                } else if (exp[k] == '-') {
                                    dp[i][j].push_back(l - r);
                                } else {
                                    dp[i][j].push_back(l * r);
                                }
                            }
                        }
                    }
                }
            }
        }

        return dp[0][n-1];
    }
};