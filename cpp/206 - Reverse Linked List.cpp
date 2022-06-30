/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
            
        // var
        ListNode* prev = NULL;
        ListNode* result = NULL;
       
        while (head) {
            prev = result;
            result = new ListNode(head->val);
            result->next = prev;
            head = head->next;
        }
        return result;
    }
};