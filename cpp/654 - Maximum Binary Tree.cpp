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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        
        // var
        int idx;
        vector<int> left;
        vector<int> right;
        TreeNode *head = new TreeNode(nums[0]);
        
        // init
        idx = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > head->val) {
                idx = i;
                head->val = nums[i];
            }
        }
        
        if (idx > 0)
            left = vector<int>(nums.begin(), nums.begin() + idx);
        if (idx + 1 < nums.size())
            right = vector<int>(nums.begin() + idx + 1, nums.end());
        
        head->left = constructMaximumBinaryTree(left);
        head->right = constructMaximumBinaryTree(right);
                                                 
        return head;
    }
};
