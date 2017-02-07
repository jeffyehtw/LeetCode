class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        
        // var
        int index = -1;
        
        // init
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                index = i;
                break;
            }
        }
        
        if (nums[0] > target) {
            vector<int> v(nums.begin() + index + 1, nums.end());
            int result = index > -1 ? binary_search(v, target) : binary_search(nums, target);
            return result == -1 ? -1 : result + index + 1;
        }
        else if (nums[0] < target) {
            vector<int> v(nums.begin(), nums.begin() + index + 1);
            int result = index > -1 ? binary_search(v, target) : binary_search(nums, target);
            return result == -1 ? -1 : result;
        }
        else {
            return 0;
        }
    }
    
    int binary_search(vector<int> nums, int target) {
        // var
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // var
            int middle = (left + right) / 2;
            
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] > target)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return -1;
    }
};