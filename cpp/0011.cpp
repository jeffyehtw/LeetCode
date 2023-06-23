class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ret = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                ret = max(ret, (right - left) * height[left]);
                left++;
            } else {
                ret = max(ret, (right - left) * height[right]);
                right--;
            }
        }

        return ret;
    }
};
