class Solution {
public:
    int minOperations(string s) {
         char maxi = 'a', mini = 'z'; 
        int n = s.length(); 

        for (int i = 0; i < n; i++) { 
            maxi = max(maxi, s[i]); 
            mini = min(mini, s[i]); 
        } 

        if (is_sorted(s.begin(), s.end())) { 
            return 0; 
        } 

        if (n == 2) { 
            return -1; 
        } 

        if (s[0] == mini || s[n - 1] == maxi) { 
            return 1; 
        } 

        for (int i = 1; i < n - 1; i++) { 
            if (s[i] == mini || s[i] == maxi) { 
                return 2; 
            } 
        } 

        return 3; 
    }
};