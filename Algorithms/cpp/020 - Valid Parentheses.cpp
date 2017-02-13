class Solution {
public:
    bool isValid(string s) {
        // var
        stack<char> st;
        map<char, char> m;
        
        // init
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else if (st.size() == 0 || st.top() != m[s[i]]) {
                return false;
            }
            else {
                st.pop();
            }
        }
        
        if (st.size() > 0)
            return false;
        
        return true;
    }
};