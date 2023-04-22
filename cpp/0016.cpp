class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = INT_MAX;
        int min = INT_MAX;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            if ((i > 0) && (nums[i] == nums[i - 1])) {
                continue;
            }

            while (left < right) {
                int sum = -target;
                
                sum += nums[i];
                sum += nums[left];
                sum += nums[right];

                if (sum == 0) {
                    return sum + target;
                } else if (sum > 0) {
                    if (sum < min) {
                        min = sum;
                        ret = sum + target;
                    }
                    right--;
                } else {
                    if (-sum < min) {
                        min = -sum;
                        ret = sum + target;
                    }
                    left++;
                }
            }
        }

        return ret;
    }
};
