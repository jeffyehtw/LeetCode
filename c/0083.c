/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* ret;
    struct ListNode* index;
    
    if (!head) {
        return NULL;
    }
    
    ret = malloc(sizeof(struct ListNode));
    index = ret;
    index->val = head->val;
    index->next = NULL;
    
    while(head->next) {
        if (head->val != head->next->val) {
            index->next = malloc(sizeof(struct ListNode));
            index = index->next;
            index->val = head->next->val;
            index->next = NULL;
        }
        head = head->next;
    }
    
    return ret;
}