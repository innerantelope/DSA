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
   void dfs(TreeNode* root,vector<int>&path,vector<vector<int>>&ans,int targetSum){
        if(root==nullptr) return;
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && root->val==targetSum){
            ans.push_back(path);
        }
        dfs(root->left,path,ans,targetSum-root->val);
        dfs(root->right,path,ans,targetSum-root->val);
        path.pop_back();
   }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        vector<vector<int>>ans;
        dfs(root,path,ans,targetSum);
        return ans;
        
    }
};