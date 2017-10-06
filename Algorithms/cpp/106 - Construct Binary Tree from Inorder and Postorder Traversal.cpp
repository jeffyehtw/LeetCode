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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        
        // var
        int mid = 0;
        TreeNode* root = new TreeNode(postorder.back());        
        
        // init
        postorder.pop_back();
        while (inorder[mid] != root->val)
            mid++;
        
        if (inorder.size() == 1)
            return root;
        
        vector<int> left = mid > 0 ? vector<int>(inorder.begin(), inorder.begin() + mid) : vector<int>();
        vector<int> right = mid + 1 < inorder.size() ? vector<int>(inorder.begin() + mid + 1, inorder.end()) : vector<int>();
        
        root->right = right.size() > 0 ? buildTree(right, postorder) : NULL;
        root->left = left.size() > 0 ? buildTree(left, postorder) : NULL;
        
        return root;
    }
};