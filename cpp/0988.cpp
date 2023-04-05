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
    string ret;
    void traversal(TreeNode* root, string s) {
        if (root == NULL) {
            return;
        }

        s = string(1, ('a' + root->val)) + s;
        if ((root->left == NULL) && (root->right == NULL)) {
            if (ret == "") {
                ret = s;
            } else {
                ret = (ret < s) ? ret : s;
            }
        } else {
            traversal(root->left, s);
            traversal(root->right, s);
        }
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        traversal(root, "");
        return ret;
    }
};
