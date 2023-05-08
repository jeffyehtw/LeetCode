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
        } else {
            levels[level - 1] += root->val;
        }

        traversal(root->left, level + 1);
        traversal(root->right, level + 1);
    }
public:
    int maxLevelSum(TreeNode* root) {
        int max = INT_MIN;
        int idx = -1;

        if (root == NULL) {
            return 0;
        }
        traversal(root, 1);
        for (int i = 0; i < levels.size(); i++) {
            if (max < levels[i]) {
                max = levels[i];
                idx = i;
            }
        }

        return idx + 1;
    }
};
