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
    vector<vector<int>> levels;
    void traverse(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        if (level > levels.size()) {
            levels.push_back(vector<int>({ root->val }));
        } else {
            if (level % 2 == 1) {
                levels[level - 1].push_back(root->val);
            } else {
                levels[level - 1].insert(levels[level - 1].begin(), root->val);
            }
        }
        traverse(root->left, level + 1);
        traverse(root->right, level + 1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traverse(root, 1);
        return levels;
    }
};
