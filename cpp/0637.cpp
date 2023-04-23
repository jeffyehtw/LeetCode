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
    vector<double> ret;
    vector<pair<double, int>> levels;
    void traversal(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }

        if (level > levels.size()) {
            levels.push_back({ 0, 0 });
        }
        levels[level - 1].first += root->val;
        levels[level - 1].second++;

        if (root->left) {
            traversal(root->left, level + 1);
        }
        if (root->right) {
            traversal(root->right, level + 1);
        }
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        traversal(root, 1);
        for (int i = 0; i < levels.size(); i++) {
            ret.push_back(levels[i].first / levels[i].second);
        }
        return ret;
    }
};
