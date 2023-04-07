class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ret;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                ret.push_back(left + 1);
                ret.push_back(right + 1);
                return ret;
            }
            if (sum > target) {
                right--;
            } else {
                left++;
            }
        }

        return ret;
    }
};
