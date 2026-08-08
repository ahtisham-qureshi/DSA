class Solution {
public:
    int maxProduct(int n) {
        int x = 0;
        int y = 0;

        while(n){
            int temp = n%10;
            if(temp>x){
                y = x;
                x = temp;
            }else if(temp>y){
                y = temp;
            }
            
            n /= 10;
        } 

        return x*y;
    }
};