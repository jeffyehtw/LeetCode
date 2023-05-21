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
private:
    TreeNode* great;
    TreeNode* less;
    void insert(TreeNode* root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
        } else {
            TreeNode* idx = root;
            while (true) {
                if (val < idx->val) {
                    if (idx->left == NULL) {
                        idx->left = new TreeNode(val);
                        break;
                    } else {
                        idx = idx->left;   
                    }
                } else {
                    if (idx->right == NULL) {
                        idx->right = new TreeNode(val);
                        break;
                    } else {
                        idx = idx->right;
                    }
                }
            }
        }
    }
    void traversal(TreeNode* root, int target) {
        if (root == NULL) {
            return;
        }
        if (root->val > target) {
            insert(great, root->val);
        } else {
            insert(less, root->val);
        }
        traversal(root->left, target);
        traversal(root->right, target);
    }
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        great = new TreeNode(-1);
        less = new TreeNode(-1);
        traversal(root, target);
        return vector<TreeNode*>({ less->right, great->right });
    }
};
