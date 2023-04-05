/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    vector<vector<Node*>> lvtree;
    int height(Node* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    void traversal(Node* root, int level) {
        if (root == NULL) {
            return;
        }
        traversal(root->left, level + 1);
        traversal(root->right, level + 1);
        lvtree[level].push_back(root);
    }
public:
    Node* connect(Node* root) {
        int h = height(root);

        if (root == NULL) {
            return root;
        }

        lvtree = vector<vector<Node*>>(h, vector<Node*>());
        traversal(root, 0);

        // cout << "h " << h << endl;
        for (int i = 0; i < lvtree.size(); i++) {
            // cout << "w " << lvtree[i].size() << endl;
            for (int j = 1; j < lvtree[i].size(); j++) {
                lvtree[i][j - 1]->next = lvtree[i][j];
            }
        }

        return root;
    }
};
