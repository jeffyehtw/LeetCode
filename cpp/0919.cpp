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
class CBTInserter {
private:
    queue<TreeNode*> next;
    TreeNode* self;
    
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q;

        self = root;
        
        q.push(root);
        while (!q.empty()) {
            if ((q.front()->left == NULL) 
                || (q.front()->right == NULL)) {
                next.push(q.front());
            }
            if (q.front()->left) {
                q.push(q.front()->left);
            }
            if (q.front()->right) {
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
    
    int insert(int val) {
        int ret = next.front()->val;

        if (next.front()->left == NULL) {
            next.front()->left = new TreeNode(val);
            next.push(next.front()->left);
        } else {
            next.front()->right = new TreeNode(val);
            next.push(next.front()->right);
            next.pop();
        }

        return ret;
    }
    
    TreeNode* get_root() {
        return self;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
