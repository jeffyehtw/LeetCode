/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int len(ListNode* head) {
        int ret = 0;

        if (head == NULL) {
            return ret;
        }
        while (head) {
            ret++;
            head = head->next;
        }

        return ret;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alen = len(headA);
        int blen = len(headB);

        if (min(alen, blen) == 0) {
            return NULL;
        }

        if (alen > blen) {
            for (int i = 0; i < alen - blen; i++) {
                headA = headA->next;
            }
        } else {
            for (int i = 0; i < blen - alen; i++) {
                headB = headB->next;
            }
        }

        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};
