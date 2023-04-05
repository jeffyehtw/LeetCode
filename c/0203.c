/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* ret = NULL;
    struct ListNode* index = NULL;
    
    if (head == NULL) {
        return ret;
    }
    
    while (head) {
        if (val != head->val) {
            if (ret == NULL) {
                ret = malloc(sizeof(struct ListNode));
                ret->next = NULL;
                index = ret;
            }
            else {
                index->next = malloc(sizeof(struct ListNode));
                index = index->next;
                index->next = NULL;
            }
            index->val = head->val;
        }
        head = head->next;
    }
    
    return ret;
}