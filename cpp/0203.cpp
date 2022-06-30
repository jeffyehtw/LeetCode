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
    ListNode* removeElements(ListNode* head, int val) {
        // prev
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        
        // var
        ListNode* it = new_head;
        ListNode* prev = it;
        
        it = it->next;
        while (it) {
            if (it->val == val)
                prev->next = it->next;
            else
                prev = it;
            it = it->next;
        }
        return new_head->next;
    }
};