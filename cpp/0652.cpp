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
private:
    vector<TreeNode*> trees;
    unordered_map<string, bool> seen;
    string traverse(TreeNode* root) {
        string ret = "";

        if (root == NULL) {
            return "#";
        }
        
        ret += traverse(root->left);
        ret += ",";
        ret += traverse(root->right);
        ret += ",";
        ret += to_string(root->val);

        if (seen.find(ret) == seen.end()) {
            seen[ret] = true;
        } else {
            if (seen[ret]) {
                trees.push_back(root);
                seen[ret] = false;
            }
        }

        return ret;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root == NULL) {
            return trees;
        }
        traverse(root);
        return trees;
    }
};
