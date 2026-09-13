class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int,int>> a, b;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(img1[i][j]) a.push_back({i,j});
                if(img2[i][j]) b.push_back({i,j});
            }
        }

        map<pair<int,int>,int> m;
        int ans = 0;

        for(auto [r1,c1] : a){
            for(auto [r2,c2] : b){
                ans = max(ans,++m[{r2-r1,c2-c1}]);
            }
        }

        return ans;
    }
};