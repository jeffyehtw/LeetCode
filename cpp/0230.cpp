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
    vector<int> v;
    void traversal(TreeNode* root, int k) {
        if (root == NULL) {
            return;
        }

        traversal(root->left, k);
        v.push_back(root->val);
        if (v.size() == k) {
            return;
        }
        traversal(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        traversal(root, k);
        return v[k - 1];
    }
};
