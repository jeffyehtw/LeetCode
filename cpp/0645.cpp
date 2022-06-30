class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // var
        int missing;
        int duplicate;
        int n = nums.size();
        map<int, bool> mapping;
        
        for (int i = 0; i < n; i++) {
            if (mapping[nums[i]]) {
                duplicate = nums[i];
            }
            else {
                mapping[nums[i]] = true;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!mapping[i + 1])
                missing = i + 1;
        }
        
        return vector<int>({duplicate, missing});
    }
};