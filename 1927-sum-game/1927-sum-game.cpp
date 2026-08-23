class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sum_diff = 0;
        int q_diff = 0;

        // Process the first half
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                q_diff++;
            } else {
                sum_diff += (num[i] - '0');
            }
        }

        // Process the second half
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                q_diff--;
            } else {
                sum_diff -= (num[i] - '0');
            }
        }

        return sum_diff + (q_diff * 4.5) != 0.0;
    }
};