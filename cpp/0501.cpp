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
    vector<int> findMode(TreeNode* root) {
        if (!root)
            return vector<int>();
        
        traversal(root);
        
        return result;
    }
private:
    // var
    vector<int> result;
    map<int, int> mapping;
    int max_val = -1 * INT_MAX;
    
    void traversal(TreeNode* root) {
        if (!root)
            return;
        
        mapping[root->val]++;
        
        if (mapping[root->val] == max_val) {
            result.push_back(root->val);
        }
        else if (mapping[root->val] > max_val) {
            max_val = mapping[root->val];
            result.clear();
            result.push_back(root->val);
        }
        
        traversal(root->left);
        traversal(root->right);
    }
};