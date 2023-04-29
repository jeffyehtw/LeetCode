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
    vector<Node*> next;
    void traversal(Node* root, int level) {
        if (root == NULL) {
            return;
        }

        if (level > next.size()) {
            next.push_back(root);
        } else {
            next[level - 1]->next = root;
            next[level - 1] = root;
        }

        if (root->left) {
            traversal(root->left, level + 1);
        }
        if (root->right) {
            traversal(root->right, level + 1);
        }
    }
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        traversal(root, 1);
        return root;
    }
};
