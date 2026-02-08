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