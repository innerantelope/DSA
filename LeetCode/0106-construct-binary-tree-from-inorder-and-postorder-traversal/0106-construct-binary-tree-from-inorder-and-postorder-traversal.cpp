class Solution {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& postIdx, int left, int right, unordered_map<int, int>& inMap) {
        if (left > right) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int inIdx = inMap[rootVal];

        root->right = helper(inorder, postorder, postIdx, inIdx + 1, right, inMap);
        root->left = helper(inorder, postorder, postIdx, left, inIdx - 1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        int postIdx = postorder.size() - 1;
        return helper(inorder, postorder, postIdx, 0, inorder.size() - 1, inMap);
    }
};
