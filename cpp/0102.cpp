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
    vector<vector<int>> ret;
    void traversal(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }

        if (ret.size() < level) {
            ret.push_back(vector<int>());
        }
        ret[level - 1].push_back(root->val);
        traversal(root->left, level + 1);
        traversal(root->right, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        traversal(root, 1);
        return ret;
    }
};
