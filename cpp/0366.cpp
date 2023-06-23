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
    vector<vector<int>> ret;
    unordered_map<TreeNode*, TreeNode*> parents;
    void link(TreeNode* root, TreeNode* parent) {
        if (root == NULL) {
            return;
        }
        parents[root] = parent;
        link(root->left, root);
        link(root->right, root);
    }
    bool leaf(TreeNode* root) {
        return (root->left == NULL) && (root->right == NULL);
    }
    void remove(TreeNode* parent, TreeNode* child) {
        if (parent->left == child) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    }
    void traverse(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (leaf(root)) {
            ret.back().push_back(root->val);
            remove(parents[root], root);
        } else {
            traverse(root->left);
            traverse(root->right);
        }
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (root == NULL) {
            return ret;
        }

        link(root, NULL);
        while (!leaf(root)) {
            ret.push_back(vector<int>());
            traverse(root);
        }
        ret.push_back(vector<int>({ root->val }));

        return ret;
    }
};
