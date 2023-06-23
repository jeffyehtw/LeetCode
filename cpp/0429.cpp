/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<vector<int>> levels;
    void traverse(Node* root, int level) {
        if (root == NULL) {
            return;
        }
        if (level > levels.size()) {
            levels.push_back(vector<int>({ root->val }));
        } else {
            levels[level - 1].push_back(root->val);
        }
        for (int i = 0; i < root->children.size(); i++) {
            traverse(root->children[i], level + 1);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        traverse(root, 1);
        return levels;
    }
};
