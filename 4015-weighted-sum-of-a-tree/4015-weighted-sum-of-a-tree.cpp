class Solution {
public:
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> child(n);

        for(int i = 1;i<n;i++){
            child[parent[i]].push_back(i);
        }

        vector<int> dep(n);
        dep[0] = 1;

        queue<int> q;
        q.push(0);

        int h = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : child[u]){
                dep[v] = dep[u] + 1;
                h = max(h,dep[v]);
                q.push(v);
            }
        }

        long long ans = 0;

        for(int i = 0;i<n;i++){
            ans += (long long)nums[i]*(h-dep[i]+1);
        }

        return ans;
    }
};