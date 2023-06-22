class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        stack<int> st;
        vector<int> dp(s.length() + 1, 0);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    continue;
                } else {
                    int left = st.top();
                    int len = i - left + 1 + dp[left];
                    st.pop();
                    dp[i + 1] = len;
                }
            }
        }
        for (int i = 0; i < dp.size(); i++) {
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};
