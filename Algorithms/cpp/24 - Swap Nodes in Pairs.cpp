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
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return NULL;
            
        // var
        ListNode* new_head = new ListNode(0);
        ListNode* it = new_head;
        
        // init
        new_head->next = head;
        
        while (it && it->next && it->next->next) {
            // var
            ListNode* a = it->next;
            ListNode* b = it->next->next;
            
            a->next = b->next;
            b->next = a;
            it->next = b;
            
            // next round
            it = it->next->next;
        }
        return new_head->next;
    }
};