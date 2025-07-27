class Codec {
public:
    // Serialize a tree to string using BFS
    string serialize(TreeNode* root) {
        if (!root) return "null";

        queue<TreeNode*> q;
        q.push(root);
        string result;

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }

        result.pop_back(); // remove last comma
        return result;
    }

    // Deserialize string back to tree using BFS
    TreeNode* deserialize(string data) {
        if (data == "null") return nullptr;

        vector<string> vals;
        string val;
        stringstream ss(data);
        while (getline(ss, val, ',')) {
            vals.push_back(val);
        }

        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < vals.size()) {
            TreeNode* node = q.front(); q.pop();

            // Left child
            if (vals[i] != "null") {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;

            // Right child
            if (i < vals.size() && vals[i] != "null") {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};
