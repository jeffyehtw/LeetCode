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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // var
        vector<int> merge;
        vector<vector<int>> result;
        
        if (!root)
            return result;
        
        // init
        result.push_back(vector<int>(1, root->val));
        
        // next level
        vector<vector<int>> left = levelOrder(root->left);;
        vector<vector<int>> right = levelOrder(root->right);;
        
        // merge subtree
        for (int i = 0; i < max(left.size(), right.size()); i++) {
            if (left.size() > i)
                merge.insert(merge.end(), left[i].begin(), left[i].end());
            if (right.size() > i)
                merge.insert(merge.end(), right[i].begin(), right[i].end());
            result.push_back(merge);
            merge.clear();
        }
        return result;
    }
};