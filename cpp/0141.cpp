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
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        if (!head->next)
            return false;
        else if (!head->next->next)
            return false;
        
        // var
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        
        while (fast && fast->next) {
            if (fast == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return false;
    }
};