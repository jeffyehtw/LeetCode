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
    void traverse(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) {
            return;
        }
        traverse(root->left, nodes);
        nodes.push_back(root->val);
        traverse(root->right, nodes);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ret;
        vector<int> n1;
        vector<int> n2;
        int i;
        int j;

        traverse(root1, n1);
        traverse(root2, n2);

        for (i = 0, j = 0; (i < n1.size()) && (j < n2.size()); ) {
            if (n1[i] < n2[j]) {
                ret.push_back(n1[i]);
                i++;
            } else {
                ret.push_back(n2[j]);
                j++;
            }
        }
        while (i < n1.size()) {
            ret.push_back(n1[i]);
            i++;
        }
        while (j < n2.size()) {
            ret.push_back(n2[j]);
            j++;
        }

        return ret;
    }
};
