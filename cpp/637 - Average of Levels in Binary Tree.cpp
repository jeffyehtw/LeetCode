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
    vector<double> averageOfLevels(TreeNode* root) {
        // var 
        vector<double> result;
        queue<TreeNode*> current;
        queue<TreeNode*> next;
        
        // init
        current.push(root);
        
        while(current.size() > 0) {
            // var
            double total = 0;
            int amount = current.size();
            
            while(!current.empty()) {
                // var
                TreeNode* tmp = current.front();
                total += tmp->val;
                
                if (tmp->left)
                    next.push(tmp->left);
                if (tmp->right)
                    next.push(tmp->right);
                
                current.pop();
            }
            
            // append result
            result.push_back(total / amount);
            
            // update
            current = next;
            next = queue<TreeNode*>();
        }
        return result;
    }
};