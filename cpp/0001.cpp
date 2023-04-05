class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> known;
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            if (known.find(nums[i]) != known.end()) {
                ret.push_back(i);
                ret.push_back(known[nums[i]]);
                break;
            }
            known[target - nums[i]] = i;
        }

        return ret;
    }
};
