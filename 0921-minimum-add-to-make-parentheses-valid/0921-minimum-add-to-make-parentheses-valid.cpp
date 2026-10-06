class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int curr = 0;

        for(char ch : s){
            if(ch == '('){
                curr++;
            }else{
                if(curr == 0){
                    ans++;
                }else{
                    curr--;
                }
            }
        }

        ans += curr;
        return ans;
    }
};