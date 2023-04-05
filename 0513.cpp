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
    int findBottomLeftValue(TreeNode* root) {
        // var
        queue<TreeNode*> q;
        
        // init
        q.push(root);
        
        while (!q.empty()) {
            // var
            queue<TreeNode*> bk;
            queue<TreeNode*> tmp;
            
            while (!q.empty()) {
                bk.push(q.front());
                if (q.front()->left)
                    tmp.push(q.front()->left);
                if (q.front()->right)
                    tmp.push(q.front()->right);
                q.pop();
            }
            
            if (tmp.empty()) {
                q = bk;
                break;
            }
            
            q = tmp;
        }
        return q.front()->val;
    }
};