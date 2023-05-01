class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        multiset<int> ms;

        for (int i = 0; i < k; i++) {
            ms.insert(nums[i]);
        }
        ret.push_back(*(ms.rbegin()));

        for (int i = k; i < nums.size(); i++) {
            ms.insert(nums[i]);
            ms.erase(ms.find(nums[i - k]));
            ret.push_back(*(ms.rbegin()));
        }

        return ret;
    }
};
