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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // var
        ListNode* result = new ListNode(0);
        ListNode* it = result;
        
        while (l1 && l2) {
            // var
            bool less_than = l1->val < l2->val;
            
            it->next = new ListNode(less_than ? l1->val : l2->val);
            it = it->next;
            
            if (less_than)
                l1 = l1->next;
            else
                l2 = l2->next;
        }
        it->next = l1 ? l1 : l2;
        return result->next;
    }
};