/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    if (fast != NULL) {
        fast = head->next;
    }
    
    while (slow && fast) {
        if (slow == fast) {
            return true;
        }
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        }
        slow = slow->next;
    }
    
    return false;
}