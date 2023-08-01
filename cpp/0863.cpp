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
private:
    unordered_map<TreeNode*, TreeNode*> parents;
    unordered_map<TreeNode*, bool> visit;
    void traverse(TreeNode* root, TreeNode* parent) {
        if (root == NULL) {
            return;
        }
        if (parent != NULL) {
            parents[root] = parent;
        }
        traverse(root->left, root);
        traverse(root->right, root);
    }
    bool visited(TreeNode* root) {
        return !(visit.find(root) == visit.end());
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        vector<int> ret;

        traverse(root, NULL);

        q.push(target);
        visit[target] = true;

        for (int i = 0; i < k; i++) {
            int size = q.size();

            for (int j = 0; j < size; j++) {
                TreeNode* cur = q.front();
                TreeNode* parent = NULL;

                if (parents.find(cur) != parents.end()) {
                    parent = parents[cur];
                }

                if (cur->left && !visited(cur->left)) {
                    visit[cur->left] = true;
                    q.push(cur->left);
                }
                if (cur->right && !visited(cur->right)) {
                    visit[cur->right] = true;
                    q.push(cur->right);
                }
                if ((parent != NULL) && !visited(parent)) {
                    visit[parent] = true;
                    q.push(parent);
                }

                q.pop();
            }
        }

        while (!q.empty()) {
            ret.push_back(q.front()->val);
            q.pop();
        }

        return ret;
    }
};
