class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for(int i = n;;i++){
            int ans = 1;
            int j = i;
            while(j>0){
                ans *= j%10;
                j /= 10;
            }
            if(ans%t == 0) return i;
        }

        return -1;
    }
};