class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int right = 0;
        int ret = 0;
        int _min = INT_MAX;
        int _max = INT_MIN;
        multiset<int> ms;

        while (right < nums.size()) {
            ms.insert(nums[right]);
            _min = *(ms.begin());
            _max = *(ms.rbegin());
            while (_max - _min > limit) {
                ms.erase(ms.find(nums[left]));
                _min = *(ms.begin());
                _max = *(ms.rbegin());
                left++;
            }
            ret = max(ret, right - left + 1);
            right++;
        }

        return ret;
    }
};
