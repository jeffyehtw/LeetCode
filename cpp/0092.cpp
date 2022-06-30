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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // var
        ListNode* it;
        ListNode* left;
        ListNode* right;
        ListNode* new_head;
        ListNode* reverse_head;
        
        // init
        new_head = new ListNode(0);
        new_head->next = head;
        it = new_head;
        
        if (m == n)
            return head;
        
        // find var index
        for (int i = 0; i < n; i++) {
            if (i == m - 1)
                left = it;
            else if (i == m)
                reverse_head = it;
            it = it->next;
        }
        right = it->next;
        it->next = NULL;
        
        // reverse from m to n
        left->next = reverseList(reverse_head);
        
        // append right
        if (right) {
            it = left;
            while (it->next) 
                it = it->next;
            it->next = right;
        }
        
        return new_head->next;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
            
        // var
        ListNode* prev = NULL;
        ListNode* result = NULL;
       
        while (head) {
            prev = result;
            result = new ListNode(head->val);
            result->next = prev;
            head = head->next;
        }
        
        return result;
    }
};