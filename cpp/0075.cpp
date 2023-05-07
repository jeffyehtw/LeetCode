class Solution {
public:
    void sortColors(vector<int>& nums) {
        int idx = 0;
        vector<int> v(3, 0);
        
        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]]++;
        }
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i]; j++) {
                nums[idx] = i;
                idx++;
            }
        }
    }
};
