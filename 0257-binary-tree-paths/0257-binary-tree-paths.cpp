/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void support(TreeNode* root,vector<string>&ans,string temp){
        if(!root) return;
        
        if (!temp.empty()) temp += "->";
        temp += to_string(root->val);

        if(!root->left && !root->right){
            ans.push_back(temp);
            return;
        }

        support(root->left,ans,temp);
        support(root->right,ans,temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        support(root,ans,"");
        return ans;
    }
};