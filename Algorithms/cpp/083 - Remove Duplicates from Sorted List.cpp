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
        // var
        ListNode* it = head;
        
        while (it && it->next) {
            if (it->val == it->next->val)
                it->next = it->next->next;
            else
                it = it->next;
        }
        return head;
    }
};