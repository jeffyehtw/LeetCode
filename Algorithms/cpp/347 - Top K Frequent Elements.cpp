// var
map<int, int> m;

bool compare(int x, int y) {
    return m[x] > m[y];
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // init
        m.clear();
        
        for (int i = 0; i < nums.size();) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
                i++;
            }
            else {
                m[nums[i]]++;
                nums.erase(nums.begin() + i);
            }
        }
        sort(nums.begin(), nums.end(), compare);
        return vector<int>(nums.begin(), nums.begin() + k);
    }
};