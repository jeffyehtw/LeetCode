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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        
        // var
        int n = len(head);
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        
        // init
        k %= n;
        ListNode* prev = new_head;
        ListNode* it = new_head->next;
        
        while (it) {
            if (is_kth(it, k)) {
                // no need to change
                if (it == head)
                    break;

                // change head
                new_head->next = it;
                
                // link to old head
                while (it->next)
                    it = it->next;
                it->next = head;
                
                // split old end link
                prev->next = NULL;

                break;
            }
            else {
                prev = it;
                it = it->next;
            }
        }
        return new_head->next;
    }
    
    bool is_kth(ListNode* head, int k) {
        for (int i = 0; i < k && head; i++)
            head = head->next;
        return head == NULL;
    }
    
    int len(ListNode* head) {
        // var
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }
};