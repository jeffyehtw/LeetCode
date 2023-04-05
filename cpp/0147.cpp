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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return head;
        
        // var
        ListNode* prev;
        ListNode* index;
        ListNode* new_head = new ListNode(0);
        
        // init
        prev = head;
        index = head->next;
        new_head->next = head;
       
        while (index) {
            // var
            bool ok = false;
            ListNode* tmp = new_head;
            
            while(tmp->next != index) {
                if (index->val <= tmp->next->val) {
                    prev->next = index->next;
                    index->next = tmp->next;
                    tmp->next = index;
                    ok = true;
                    break;
                }
                tmp = tmp->next;
            }
            
            // update
            index = ok ? prev->next : index->next;
            prev = ok ? prev : prev->next;
        }
        return new_head->next;
    }
};