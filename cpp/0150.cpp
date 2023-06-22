class Solution {
private:
    int to_int(string s) {
        int ret = 0;
        int index = 0;
        int positive = true;

        if (s[0] == '-') {
            positive = false;
            index++;
        }
        for (; index < s.length(); index++) {
            ret *= 10;
            ret += (s[index] - '0');
        }

        return (positive ? ret : -ret);
    }
public:
    int evalRPN(vector<string>& tokens) {
        int ret = 0;
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            if (isdigit(tokens[i][0]) || tokens[i].length() > 1) {
                st.push(to_int(tokens[i]));
            } else {
                int cur = st.top();

                st.pop();
                if (tokens[i][0] == '+') {
                    cur = st.top() + cur;
                    st.pop();
                } else if (tokens[i][0] == '-') {
                    cur = st.top() - cur;
                    st.pop();
                } else if (tokens[i][0] == '*') {
                    cur = st.top() * cur;
                    st.pop();
                } else if (tokens[i][0] == '/') {
                    cur = st.top() / cur;
                    st.pop();
                }
                st.push(cur);
            } 
        }
        return st.top();
    }
};
