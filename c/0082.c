/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    int val;
    int count;
    struct ListNode* ret = NULL;
    struct ListNode* index = NULL;
    
    if (head == NULL) {
        return ret;
    }
    
    val = head->val;
    count = 1;
    
    while (head->next) {
        if (val != head->next->val) {
            if (count == 1) {
                if (ret == NULL) {
                    ret = malloc(sizeof(struct ListNode));
                    ret->next = NULL;
                    index = ret;
                }
                else {
                    index->next = malloc(sizeof(struct ListNode));
                    index->next->next = NULL;
                    index = index->next;
                }
                index->val = val;
            }
            val = head->next->val;
            count = 0;
        }
        count++;
        head = head->next;
    }
    
    if (count == 1) {
        if (ret == NULL) {
            ret = malloc(sizeof(struct ListNode));
            ret->next = NULL;
            index = ret;
        }
        else {
            index->next = malloc(sizeof(struct ListNode));
            index->next->next = NULL;
            index = index->next;
        }
        index->val = val;
    }
    
    return ret;
}