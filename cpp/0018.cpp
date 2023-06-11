class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int n = nums.size();

        if (n < 4) {
            return ret;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if ((i > 0) && (nums[i - 1] == nums[i])) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                int left = j + 1;
                int right = n - 1;
                long val = (long)target - nums[i] - nums[j];

                if ((j > i + 1) && (nums[j - 1] == nums[j])) {
                    continue;
                }
                while (left < right) {
                    if (nums[left] + nums[right] == val) {
                        ret.push_back({ 
                            nums[i], nums[j], nums[left], nums[right] 
                        });
                        left++;
                        while ((left < right) && (nums[left - 1] == nums[left])) {
                            left++;
                        }
                        right--;
                        while ((left < right) && (nums[right] == nums[right + 1])) {
                            right--;
                        }
                    } else if (nums[left] + nums[right] > val) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }

        return ret;
    }
};
