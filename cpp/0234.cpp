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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* index = head;

        while (index != NULL) {
            st.push(index->val);
            index = index->next;
        }
        index = head;
        while (index != NULL) {
            if (index->val != st.top()) {
                return false;
            }
            st.pop();
            index = index->next;
        }

        return true;
    }
};
