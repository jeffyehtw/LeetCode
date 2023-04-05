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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 1;
        TreeNode* ret = NULL;
        vector<int> left;
        vector<int> right;

        if (preorder.size() == 0) {
            return ret;
        } else if (preorder.size() == 1) {
            ret = new TreeNode(preorder[0]);
            return ret;
        }

        for (; i < preorder.size() && preorder[0] > preorder[i]; i++);
        
        left = vector<int>(preorder.begin() + 1, preorder.begin() + i);
        right = vector<int>(preorder.begin() + i, preorder.end());

        ret = new TreeNode(preorder[0]);
        ret->left = bstFromPreorder(left);
        ret->right = bstFromPreorder(right);        

        return ret;
    }
};
