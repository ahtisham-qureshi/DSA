class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int c = 0;
        for(char ch : s){
            if(ch == '('){
                if(c != 0){
                    ans += ch;
                }
                c++;
            }else if(ch == ')'){
                if(c != 1){
                    ans += ch;
                }
                c--;
            }
        }

        return ans;
    }
};