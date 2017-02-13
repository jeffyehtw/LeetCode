class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return false;
        
        // var
        vector<int> v;
        int index = -1;
        
        // init
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                index = i;
                break;
            }
        }
        
        if (nums[0] > target)
            v = vector<int>(nums.begin() + index + 1, nums.end());
        else if (nums[0] < target)
            v = vector<int>(nums.begin(), nums.begin() + index + 1);
        else
            return true;
            
        return index > -1 ? binary_search(v, target) : binary_search(nums, target);
    }
    
    bool binary_search(vector<int> nums, int target) {
        // var
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // var
            int middle = (left + right) / 2;
            
            if (nums[middle] == target)
                return true;
            else if (nums[middle] > target)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return false;
    }
};