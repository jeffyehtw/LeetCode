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
    set<int> st;
    void traversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        st.insert(root->val);
        traversal(root->left);
        traversal(root->right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        traversal(root);
        if (st.size() < 2) {
            return -1;
        } else {
            auto it = st.begin();
            it++;
            return *it;
        }
    }
};
