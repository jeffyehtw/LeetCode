class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char map[256] = { 0 };

        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{'; 

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (st.empty() == false && st.top() == map[s[i]]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
