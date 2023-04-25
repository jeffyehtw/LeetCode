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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* ret;
        vector<int> left;
        vector<int> right;
        int idx = 0;
        
        if (inorder.size() == 0) {
            return NULL;
        } else if (inorder.size() == 1) {
            ret = new TreeNode(postorder.back());
            postorder.pop_back();
            return ret;
        }

        ret = new TreeNode(postorder.back());
        postorder.pop_back();
        for (; idx < inorder.size() && inorder[idx] != ret->val; idx++);
        if (idx > 0) {
            left = vector(inorder.begin(), inorder.begin() + idx);
        }
        if (idx + 1 < inorder.size()) {
            right = vector(inorder.begin() + idx + 1, inorder.end());
        }
        ret->right = buildTree(right, postorder);
        ret->left = buildTree(left, postorder);

        return ret;
    }
};
