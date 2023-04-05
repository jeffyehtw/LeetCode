class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int index = 2;
        vector<long> ret(3, (long)INT_MIN - 1);

        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] == ret[0])
                || (nums[i] == ret[1])
                || (nums[i] == ret[2])
                || (nums[i] < ret[2])) {
                continue;
            }

            if (nums[i] > ret[0]) {
                ret[2] = ret[1];
                ret[1] = ret[0];
                ret[0] = nums[i];
            } else if (nums[i] > ret[1]) {
                ret[2] = ret[1];
                ret[1] = nums[i];
            } else if (nums[i] > ret[2]) {
                ret[2] = nums[i];
            }
        }

        if ((ret[2] < INT_MIN) || (ret[1] < INT_MIN)) {
            return ret[0];
        } else {
            return ret[2];
        }
    }
};
