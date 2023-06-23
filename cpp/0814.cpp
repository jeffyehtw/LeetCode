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
    unordered_map<TreeNode*, TreeNode*> parents;
    void link(TreeNode* root, TreeNode* parent) {
        if (root == NULL) {
            return;
        }
        parents[root] = parent;
        link(root->left, root);
        link(root->right, root);
    }
    bool valid(TreeNode* root) {
        bool ret = false;

        if (root->val == 1) {
            return true;
        } else {
            if ((root->left) && valid(root->left)) {
                return true;
            }
            if ((root->right) && valid(root->right)) {
                return true;
            }
            return false;
        }
    }
    void remove(TreeNode* root, TreeNode* parent) {
        if (parent->left == root) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    }
    void traverse(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (!valid(root)) {
            remove(root, parents[root]);
        } else {
            traverse(root->left);
            traverse(root->right);
        }
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if ((root == NULL) || !valid(root)) {
            return NULL;
        }

        link(root, NULL);
        traverse(root);

        return root;
    }
};
