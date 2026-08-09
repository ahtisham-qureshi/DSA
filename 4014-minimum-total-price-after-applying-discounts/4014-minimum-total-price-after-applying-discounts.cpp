class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());

        int n = prices.size();
        int m = discounts.size();
        double ans = 0;
        for(int i = 0;i<n;i++){
            if(i<m){
                ans += 1.0 * prices[i]*(100- discounts[i])/100.0;
            }else{
                ans += prices[i];
            }
        }

        return ans;
    }
};