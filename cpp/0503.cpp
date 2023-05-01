class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        stack<int> st;

        for (int i = nums.size() - 1; i > -1; i--) {
            st.push(nums[i]);
        }
        for (int i = nums.size() - 1; i > -1; i--) {
            if (st.empty()) {
                ret[i] = -1;
            } else {
                while (!st.empty() && st.top() <= nums[i]) {
                    st.pop();
                }
                ret[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i]);
        }

        return ret;
    }
};
