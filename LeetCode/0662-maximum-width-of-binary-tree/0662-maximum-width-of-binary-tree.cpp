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
    unsigned long long maxw=0;
    unordered_map<int,unsigned long long>leftindex;
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root,0,0);
        return maxw;
        
    }
    void dfs(TreeNode* root,int depth,unsigned long long index){
        if(!root) return;
        if(leftindex.find(depth)==leftindex.end()){
            leftindex[depth]=index;
        }
        unsigned long long width=index-leftindex[depth]+1;
        maxw=max(maxw,width);
        dfs(root->left,depth+1,2*index);
        dfs(root->right,depth+1,2*index+1);
    }
    
};