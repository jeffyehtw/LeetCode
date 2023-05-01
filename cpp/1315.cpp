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
    unordered_map<long, int> umap;
    void traversal(TreeNode* root, long idx) {
        if (root == NULL) {
            return;
        }
        umap[idx] = root->val;
        traversal(root->left, idx * 2);
        traversal(root->right, idx * 2 + 1);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int ret = 0;

        if (root == NULL) {
            return ret;
        }
        traversal(root, 1);

        for (auto it = umap.begin(); it != umap.end(); it++) {
            if ((*it).second % 2 == 0) {
                for (int i = 0; i < 4; i++) {
                    if (umap.find(4 * (*it).first + i) != umap.end()) {
                        ret += umap[4 * (*it).first + i];
                    }
                }
            }
        }

        return ret;
    }
};
