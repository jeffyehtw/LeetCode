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
    vector<vector<int>> lvtree;
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    void traversal(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }

        if (root->left) {
            traversal(root->left, level + 1);
        }
        if (root->right) {
            traversal(root->right, level + 1);
        }
        lvtree[level].push_back(root->val);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        int h = height(root);

        if (root == NULL) {
            return ret;
        }      

        lvtree = vector<vector<int>>(h, vector<int>());
        traversal(root, 0);

        for (int i = 0; i < lvtree.size(); i++) {
            ret.push_back(lvtree[i][lvtree[i].size() - 1]);
        }

        return ret;
    }
};
