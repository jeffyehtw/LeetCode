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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next)
            return NULL;
            
        // var
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        
        while (fast && fast->next) {
            // found
            if (fast == slow) {
                // find entry
                fast = head;
                while (fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return NULL;
    }
};