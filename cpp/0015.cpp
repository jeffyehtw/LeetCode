class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if ((i > 0) && (nums[i] == nums[i - 1])) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ret.push_back(vector<int>({
                        nums[i],
                        nums[left],
                        nums[right]
                    }));

                    left++;
                    right--;
                    while ((left < right) && (nums[left - 1] == nums[left])) {
                        left++;
                    }
                    while ((left < right) && (nums[right] == nums[right + 1])) {
                        right--;
                    }
                } else if (sum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return ret;
    }
};
