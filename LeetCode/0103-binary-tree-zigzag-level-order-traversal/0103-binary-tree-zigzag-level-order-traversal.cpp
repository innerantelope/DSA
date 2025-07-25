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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        dfs(root,0,res);
        return res;
    }
    void dfs(TreeNode *root,int depth,vector<vector<int>> & res){
        if(!root) return;
        if(depth==res.size()){
            res.push_back({});
        }
        //check for depth level
        if(depth%2==0){
         res[depth].push_back(root->val);}
        else{
            res[depth].insert(res[depth].begin(),root->val);
        }
        //dfs from l->r and r->l
        dfs(root->left,depth+1,res);
        dfs(root->right,depth+1,res);

    }
};