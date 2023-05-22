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
    vector<int> nodes;
    void traversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        traversal(root->left);
        nodes.push_back(root->val);
        traversal(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int ret = INT_MAX;

        traversal(root);
        for (int i = 1; i < nodes.size(); i++) {
            ret = min(ret, nodes[i] - nodes[i - 1]);
        }

        return ret;
    }
};
