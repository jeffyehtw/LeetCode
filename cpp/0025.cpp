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
private:
    int cnt;
    ListNode* cur;
    void reverse(ListNode* head) {
        if (head == NULL) {
            return;
        }
        cnt--;
        if (cnt > 0) {
            reverse(head->next);
        }
        if (cnt == 0) {
            cout << head->val << " " << cnt << endl;
            cur->next = new ListNode(head->val);
            cur = cur->next;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode fake;
        ListNode* index = &fake;

        if (head == NULL) {
            return fake.next;
        }
        while (true) {
            cnt = k;
            cur = index;
            reverse(head);
            if (cnt > 0) {
                break;
            } else {
                for (int i = 0; i < k; i++) {
                    head = head->next;
                    index = index->next;
                }
            }
        }
        while (head) {
            index->next = new ListNode(head->val);
            index = index->next;
            head = head->next;
        }

        return fake.next;
    }
};
