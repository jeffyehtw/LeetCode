class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // var
        int left = 0;
        int right = nums.size();
        
        while (left < right) {
            // var
            int middle = (left + right) / 2;
            
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] > target)
                right = middle;
            else
                left = middle;
                
            if (right - left == 1)
                break;
        }
        
        if (nums[left] < target)
            return left + 1;
        return left;
    }
};