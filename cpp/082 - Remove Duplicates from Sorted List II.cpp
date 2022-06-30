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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
            
        // var
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        
        // init
        ListNode* it = new_head->next;
        ListNode* prev = new_head;
        
        while (it && it->next) {
            // var
            ListNode* tmp = it->next;
            
            // check
            while (tmp && it->val == tmp->val) {
                tmp = tmp->next;
            }
        
            if (it->next != tmp) {
                prev->next = tmp;
                it = tmp;
            }
            else {
                prev = it;
                it = it->next;
            }
            
        }
        
        return new_head->next;
    }
};