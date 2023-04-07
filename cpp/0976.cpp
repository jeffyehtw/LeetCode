class Solution {
private:
    bool triangle(int a, int b, int c) {
        return ((a + b > c)
            && (a + c > b)
            && (b + c > a));
    }
public:
    int largestPerimeter(vector<int>& nums) {
        int ret = 0;

        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i > -1; i--) {
            for (int j = i - 1; j > 0; j--) {
                if (triangle(nums[i], nums[j], nums[j - 1])) {
                    ret = max(ret, nums[i] + nums[j] + nums[j - 1]);
                    break;
                } else {
                    continue;
                }
            }
        }

        return ret;
    }
};
