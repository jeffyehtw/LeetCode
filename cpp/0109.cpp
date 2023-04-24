/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        TreeNode* ret;

        if (head == NULL) {
            return NULL;
        } else if (head->next == NULL) {
            return new TreeNode(head->val);
        } else if (head->next->next == NULL) {
            ret = new TreeNode(head->next->val);
            ret->left = new TreeNode(head->val);
            return ret;
        }

        while (slow && fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ret = new TreeNode(slow->val);
        ret->right = sortedListToBST(slow->next);
        prev->next = NULL;
        ret->left = sortedListToBST(head);

        return ret;
    }
};
