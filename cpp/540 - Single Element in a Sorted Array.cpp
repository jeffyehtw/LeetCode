class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // var
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            // var
            int mid = (left + right) / 2;
            
            if (mid & 1) {
                if (nums[mid - 1] == nums[mid])
                    left = mid + 1;
                else if (nums[mid] == nums[mid + 1])
                    right = mid - 1;
                else
                    return mid;
            }
            else {
                if (nums[mid - 1] == nums[mid])
                    right = mid - 2;
                else if (nums[mid] == nums[mid + 1])
                    left = mid + 2;
                else
                    return mid;
            }
        }
        return nums[left];
    }
};