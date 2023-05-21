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
    double min = -1;
    int ret = -1;
    void traversal(TreeNode* root, double target) {
        if (root == NULL) {
            return;
        }
        if (min == -1) {
            min = abs(target - root->val);
            ret = root->val;
        } else if (abs(target - root->val) < min) {
            min = abs(target - root->val);
            ret = root->val;
        } else if (abs(target - root->val) == min) {
            ret = (ret > root->val) ? root->val : ret;
        }
        traversal(root->left, target);
        traversal(root->right, target);
    }
public:
    int closestValue(TreeNode* root, double target) {
        traversal(root, target);
        return ret;
    }
};
