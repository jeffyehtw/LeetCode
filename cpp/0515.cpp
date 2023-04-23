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
    vector<int> ret;
    void traversal(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }

        if (level > ret.size()) {
            ret.push_back(root->val);
        }
        ret[level - 1] = max(ret[level - 1], root->val);
        if (root->left) {
            traversal(root->left, level + 1);
        }
        if (root->right) {
            traversal(root->right, level + 1);
        }
    }
public:
    vector<int> largestValues(TreeNode* root) {
        traversal(root, 1);
        return ret;
    }
};
