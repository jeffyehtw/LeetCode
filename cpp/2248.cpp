class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ret;
        vector<int> map(1001, 0);

        for (int i = 0 ; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                map[nums[i][j]]++;
            }
        }

        for (int i = 0; i < map.size(); i++) {
            if (map[i] == nums.size()) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
