class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent; 
    void markParents(TreeNode* root, TreeNode* par = nullptr) {
        if (!root) return;
        parent[root] = par;
        markParents(root->left, root);
        markParents(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParents(root);
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (dist == k) break;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();

                if (node->left && visited.count(node->left) == 0) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if (node->right && visited.count(node->right) == 0) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                TreeNode* par = parent[node];
                if (par && visited.count(par) == 0) {
                    q.push(par);
                    visited.insert(par);
                }
            }
            dist++;
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};
