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
    unordered_map<int, pair<int, int>> umap;
    void traversal(TreeNode* root, int parent, int level) {
        if (root == NULL) {
            return;
        }
        umap[root->val] = make_pair(parent, level);
        if (root->left) {
            traversal(root->left, root->val, level + 1);
        }
        if (root->right) {
            traversal(root->right, root->val, level + 1);
        }
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) {
            return false;
        }
        traversal(root, 0, 0);
        return ((umap[x].first != umap[y].first) 
            && (umap[x].second == umap[y].second));
    }
};
