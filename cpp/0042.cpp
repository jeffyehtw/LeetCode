class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        vector<int> left = height;
        vector<int> right = height;

        for (int i = 1; i < left.size(); i++) {
            left[i] = max(left[i - 1], left[i]);
        }
        for (int i = right.size() - 2; i > -1; i--) {
            right[i] = max(right[i], right[i + 1]);
        }
        for (int i = 1; i < height.size(); i++) {
            ret += min(left[i], right[i]) - height[i];
        }

        return ret;
    }
};
