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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        unordered_map<int, int> levelSum;
        while(!q.empty()){
            TreeNode* parent = q.front().first;
            int level = q.front().second;
            q.pop();
            if(parent == nullptr) continue;
            levelSum[level]+=parent->val;
            q.push({parent->left,level+1});
            q.push({parent->right,level+1});
        
        }
        int max_val =INT_MIN;
        int min_level = 0;
        for(auto it:levelSum){
            if(it.second>max_val || (it.second == max_val && it.first < min_level))
            { max_val = it.second; 
              min_level = it.first;
            }
        }
        return min_level;
    }
};