class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int x = 0, y = 0;

        for(int num : nums){
            if(num<target){
                x++;
            }else if(num == target){
                y++;
            }
        }

        vector<int>ans;
        for(int i = x;i<x+y;i++){
            ans.push_back(i);
        }

        return ans;
    }
};