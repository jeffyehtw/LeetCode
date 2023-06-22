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
    int max = 0;
    int sum = 0;
    void traverse(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        if (level > max) {
            sum = root->val;
            max = level;
        } else if (level == max) {
            sum += root->val;
        }
        traverse(root->left, level + 1);
        traverse(root->right, level + 1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        traverse(root, 0);
        return sum;
    }
};
