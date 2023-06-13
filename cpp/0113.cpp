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
    vector<int> cur;
    vector<vector<int>> ret;
    void traverse(TreeNode* root, int target) {
        if (root == NULL) {
            return;
        }

        if (root->left || root->right) {
            cur.push_back(root->val);
            traverse(root->left, target - root->val);
            traverse(root->right, target - root->val);
            cur.pop_back();
        } else if (root->val == target) {
            cur.push_back(root->val);
            ret.push_back(cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        traverse(root, targetSum);
        return ret;
    }
};
