/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        else if (!head->next)
            return (new TreeNode(head->val));
            
        // var
        ListNode *fast = head->next->next;
        ListNode *slow = head;
        
        // find middle
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // result
        TreeNode *root = new TreeNode(slow->next->val);
        root->right = sortedListToBST(slow->next->next);
        slow->next = NULL;
        root->left = sortedListToBST(head);
        
        return root;
    }
};