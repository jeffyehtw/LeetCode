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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ret;
        ListNode* index;
        int m = 0;
        int n = 0;

        index = l1;
        while (index) {
            m++;
            index = index->next;
        }
        index = l2;
        while (index) {
            n++;
            index = index->next;
        }

        if (m > n) {
            index = &ret;
            for (int i = 0; i < m - n; i++) {
                index->next = new ListNode(l1->val);
                index = index->next;
                l1 = l1->next;
            }
        } else {
            index = &ret;
            for (int i = 0; i < n - m; i++) {
                index->next = new ListNode(l2->val);
                index = index->next;
                l2 = l2->next;
            }
        }

        for (int i = 0; i < min(m, n); i++) {
            index->next = new ListNode(l1->val + l2->val);
            index = index->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        
        for (int i = max(m, n) - 2; i > -1; i--) {
            index = ret.next;
            for (int j = 0; j < i; j++) {
                index = index->next;
            }
            if (index->next->val >= 10) {
                index->val += index->next->val / 10;
                index->next->val %= 10;
            }
        }
        if (ret.next->val >= 10) {
            index = ret.next;
            ret.next = new ListNode(index->val / 10);
            index->val %= 10;
            ret.next->next = index;
        }

        return ret.next;
    }
};
