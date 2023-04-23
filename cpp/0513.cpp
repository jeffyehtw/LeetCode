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
    vector<int> levels;
    void traversal(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }

        if (level > levels.size()) {
            levels.push_back(root->val);
        }
        if (root->left) {
            traversal(root->left, level + 1);
        }
        if (root->right) {
            traversal(root->right, level + 1);
        }
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 1);
        return levels.back();
    }
};
