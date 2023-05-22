/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool next = false;
    TreeNode* ret = NULL;
    void traversal(TreeNode* root, TreeNode* p) {
        if ((root == NULL) || (ret != NULL)) {
            return;
        }

        if (root->left) {
            traversal(root->left, p);
        }
        if (ret != NULL) {
            return;
        } else if (next) {
            ret = root;
            return;
        } else if (root->val == p->val) {
            next = true;
        }
        if (root->right) {
            traversal(root->right, p);
        }
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) {
            return NULL;
        }
        traversal(root, p);
        return ret;
    }
};
