class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;
        int temp = n;

        while(temp>0){
            int dig = temp%10;
            sum += dig;
            pro *= dig;
            temp/= 10;
        }

        return n % (sum + pro) == 0;
    }
};