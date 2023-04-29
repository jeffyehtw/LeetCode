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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode fake;
        ListNode* index = &fake;

        while (true) {
            int min = INT_MAX;
            int idx = -1;

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == NULL) {
                    continue;
                } else if (lists[i]->val < min) {
                    min = lists[i]->val;
                    idx = i;
                }
            }
            if (min == INT_MAX) {
                break;
            }

            index->next = new ListNode(min);
            index = index->next;
            lists[idx] = lists[idx]->next;
        }

        return fake.next;
    }
};
