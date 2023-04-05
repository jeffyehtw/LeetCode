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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        vector<int> tmp;

        if (root == NULL) {
            return ret;
        }

        if (root->left) {
            tmp = inorderTraversal(root->left);
            ret.insert(ret.end(), tmp.begin(), tmp.end());
        }
        ret.push_back(root->val);
        if (root->right) {
            tmp.clear();
            tmp = inorderTraversal(root->right);
            ret.insert(ret.end(), tmp.begin(), tmp.end());
        }

        return ret;        
    }
};
