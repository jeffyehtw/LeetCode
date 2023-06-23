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
    void remove(TreeNode* root, TreeNode* parent) {
        if (parent == NULL) {
            return;
        }
        if (parent->left == root) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    }
    bool leaf(TreeNode* root) {
        if (root == NULL) {
            return false;
        } else {
            return ((root->left == NULL) 
                && (root->right == NULL));
        }
    }
    void traverse(TreeNode* root, int target) {
        if (root == NULL) {
            return;
        }
        if (leaf(root) && (root->val == target)) {
            TreeNode* parent = parents[root];

            remove(root, parent);
            while (leaf(parent) && (parent->val == target)) {
                remove(parent, parents[parent]);
                parent = parents[parent];
            }
        }
        traverse(root->left, target);
        traverse(root->right, target);
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == NULL) {
            return NULL;
        }

        link(root, NULL);
        traverse(root, target);

        if (leaf(root) && (root->val == target)) {
            return NULL;
        } else {
            return root;
        }
    }
};
