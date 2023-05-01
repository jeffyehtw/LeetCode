class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        stack<pair<int, int>> st;
        
        for (int i = temperatures.size() - 1; i > -1; i--) {
            if (st.empty()) {
                ret[i] = 0;
            } else {
                while (!st.empty() && st.top().first <= temperatures[i]) {
                    st.pop();
                }
                ret[i] = st.empty() ? 0 : st.top().second - i;
            }
            st.push(make_pair(temperatures[i], i));
        }

        return ret;
    }
};
