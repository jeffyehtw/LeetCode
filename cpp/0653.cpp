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
    unordered_map<int, bool> umap;
public:
    bool findTarget(TreeNode* root, int k) {
        bool left;
        bool right;

        if (root == NULL) {
            return false;
        }

        if (umap.find(k - root->val) == umap.end()) {
            umap[root->val] = true;
        } else {
            return true;
        }

        if (root->left) {
            left = findTarget(root->left, k);
        }
        if (root->right) {
            right = findTarget(root->right, k);
        }
        
        return left || right;
    }
};
