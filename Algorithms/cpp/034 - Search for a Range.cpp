class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // var
        int tmp;
        int left;
        int right;
        int middle;
        
        // init
        middle = binary_search(nums, 0, nums.size() - 1, target);
        
        // not found
        if (middle == -1)
            return vector<int>{ -1, -1 };
         
        // find left
        tmp = middle;
        while (tmp != -1) {
            left = tmp;
            tmp = binary_search(nums, 0, tmp - 1, target);
        }
    
        // find right
        tmp = middle;   
        while (tmp != -1) {
            right = tmp;
            tmp = binary_search(nums, tmp + 1, nums.size() - 1, target);
        }
    
        return vector<int>{ left, right };
    }
    
    int binary_search(vector<int> nums, int left, int right, int target) {
        // run
        while (left <= right) {
            // var
            int middle = (left + right) / 2;
            
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return -1;
    }
};