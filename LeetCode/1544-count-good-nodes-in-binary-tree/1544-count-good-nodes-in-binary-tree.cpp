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
    int count=0;
    int dfs(TreeNode* root,int maxi){
        if(root==nullptr) return 0;
        int curr=(root->val>=maxi);
        maxi=max(maxi,root->val);
        if(root->val>=maxi) count++;
        dfs(root->left,maxi);
        dfs(root->right,maxi);
        return count;
    }
    int goodNodes(TreeNode* root) {
        int maxi=root->val;
        dfs(root,maxi);
        return count;
    }
};