/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode fake;

        fake.next = head;
        while (head) {
            ListNode* next = head->next;

            if (next == NULL) {
                head->next = NULL;
                break;
            }

            while (next && next->val != 0) {
                head->val += next->val;
                next = next->next;
            }
            if (next->next == NULL) {
                head->next = NULL;
            } else {
                head->next = next;
                head = head->next;
            }
        }

        return fake.next;
    }
};
