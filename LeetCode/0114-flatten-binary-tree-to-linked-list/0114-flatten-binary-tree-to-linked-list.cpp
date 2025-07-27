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
    TreeNode* last = nullptr;

    void flatten(TreeNode* root) {
        if (!root) return;

        if (last) {
            last->right = root;
            last->left = nullptr;
        }

        last = root;

        // Save the original left and right before recursive call
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        flatten(left);
        flatten(right);
    }
};
