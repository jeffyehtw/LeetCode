class Solution {
private:
    int _rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> acc = vector<int>(nums.begin(), nums.end());

        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        } else if (n == 3) {
            return max(nums[1], nums[0] + nums[2]);
        }

        acc[2] += acc[0];
        for (int i = 3; i < n; i++) {
            acc[i] += max(acc[i - 2], acc[i - 3]);
        }

        return max(acc[n - 1], acc[n - 2]);
    }
public:
    int rob(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        vector<int> front;
        vector<int> back;
        vector<int> both;

        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        } else if (n == 3) {
            return max(
                nums[0],
                max(nums[1], nums[2])
            );
        } else if (n == 4) {
            return max(
                nums[0] + nums[2],
                nums[1] + nums[3]
            );
        }

        front = vector<int>(nums.begin(), nums.end() - 1);
        back = vector<int>(nums.begin() + 1, nums.end());
        both = vector<int>(nums.begin() + 1, nums.end() - 1);

        ret = max(_rob(front), _rob(back));
        ret = max(ret, _rob(both));

        return ret;
    }
};
