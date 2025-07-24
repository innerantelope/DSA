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
    bool isBalanced(TreeNode* root) {
        bool isbal=true;
        height(root,isbal);
        return isbal;

        
    }
    int height(TreeNode*node,bool& isbal){
        if(node==NULL) return 0;
        int left=height(node->left,isbal);
        int right=height(node->right,isbal);
        if(abs(left-right)>1) isbal=false;
        return 1+max(left,right);
    }
};