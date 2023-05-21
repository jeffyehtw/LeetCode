/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        if (node->right) {
            Node* idx = node->right;
            while (idx && idx->left) {
                idx = idx->left;
            }
            return idx;
        } else if (node->parent) {
            Node* idx = node->parent;
            while (idx && (idx->val < node->val)) {
                idx = idx->parent;
            }
            return idx;
        } else {
            return NULL;
        }
    }
};
