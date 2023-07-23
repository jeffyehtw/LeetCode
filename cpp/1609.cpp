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
    bool valid = true;
    vector<int> levels;
    void traverse(TreeNode* root, int level) {
        if ((root == NULL) || !valid) {
            return;
        }

        if ((level % 2) == (root->val % 2)) {
            valid = false;
            return;
        }

        if (level >= levels.size()) {
            levels.push_back(root->val);
        } else {
            if (level % 2 == 0) {
                if (root->val > levels[level]) {
                    levels[level] = root->val;
                } else {
                    valid = false;
                }
            } else {
                if (root->val < levels[level]) {
                    levels[level] = root->val;
                } else {
                    valid = false;
                }
            }
        }
        traverse(root->left, level + 1);
        traverse(root->right, level + 1);
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        traverse(root, 0);
        return valid;
    }
};
