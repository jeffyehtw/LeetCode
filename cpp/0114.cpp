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
    vector<TreeNode*> v;
    void traversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        v.push_back(root);
        traversal(root->left);
        traversal(root->right);
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* index = root;

        if (root == NULL) {
            return;
        }

        traversal(root);
        for (int i = 0 ; i < v.size(); i++) {
            index->val = v[i]->val;
            index->left = NULL;
            index->right = (i < v.size() - 1) ? v[i + 1] : NULL;
            index = index->right;
        }
    }
};
