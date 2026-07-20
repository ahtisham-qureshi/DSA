class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i = 0; i<nums.size() ; i++){
            int f = nums[i];
            int s = target - f;

            if(m.find(s) != m.end()){
               ans.push_back(m[s]);
               ans.push_back(i);
               return ans;
            }
            m[f] = i;
        }

        return ans;
    }
};