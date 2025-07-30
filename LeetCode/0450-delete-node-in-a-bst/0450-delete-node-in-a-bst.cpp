/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // node found
            // if found node has not any child
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            // if found node as left subtree empty
            else if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                // if node has both the child
                TreeNode* inorder = findmin(root->right);
                root->val=inorder->val;
                root->right=deleteNode(root->right,inorder->val);
            }
        }
        return root;
    }
    TreeNode* findmin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};