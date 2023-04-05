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
    vector<string> ret;
    void traversal(TreeNode* root, string s) {
        if (root == NULL) {
            return;
        }

        if (s == "") {
            s += to_string(root->val);
        } else {
            s += "->" + to_string(root->val);
        }
        
        if ((root->left == NULL) && (root->right == NULL)) {
            ret.push_back(s);
            return;
        }

        traversal(root->left, s);
        traversal(root->right, s);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        traversal(root, "");
        return ret;
    }
};
