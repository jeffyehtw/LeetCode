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
    ListNode* oddEvenList(ListNode* head) {
        // var
        int len = 0;
        ListNode* it = head;
        ListNode* end = head;
        
        while (end && end->next) {
            end = end->next;
            len++;
        }
        
        for (int i = 0; i < (len + 1) / 2; i++) {
            end->next = it->next;
            it->next = it->next->next;
            end = end->next;
            end->next = NULL;
            it = it->next;
        }
        
        return head;
    }
};