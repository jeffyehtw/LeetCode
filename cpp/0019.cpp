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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // var
        ListNode* dummy = new ListNode(0);
        ListNode* faster = dummy;
        ListNode* slower = dummy;
        
        // init
        dummy->next = head;
        for (int i = 0; i <= n; i++)
            faster = faster->next;
        
        while (faster) {
            faster = faster->next;
            slower = slower->next;
        }
        
        // remove nth node
        slower->next = slower->next ? slower->next->next : NULL;
        
        return dummy->next;
    }
};