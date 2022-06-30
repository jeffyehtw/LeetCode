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
    bool isPalindrome(ListNode* head) {
        if (!head)
            return true;
            
        // var
        ListNode* it = head->next;
        ListNode* rev_head = new ListNode(head->val);
        
        while (it) {
            // var
            ListNode* tmp = new ListNode(it->val);
            tmp->next = rev_head;
            rev_head = tmp;
            it = it->next;
        }
        
        while (head) {
            if (head->val != rev_head->val)
                return false;
            head = head->next;
            rev_head = rev_head->next;
        }
        return true;
    }
};