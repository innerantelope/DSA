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
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool chk=true;
        while (!q.empty()) {
            int x = q.size();
            vector<int> level;
            for (int i = 0; i < x; i++) {
                TreeNode* y = q.front();
                q.pop();
                level.push_back(y->val);
                if (y->left)
                    q.push(y->left);
                if (y->right)
                    q.push(y->right);
            }
            if(chk)
               ans.push_back(level);
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            chk=!chk;
        }
        return ans;
        
    }
};