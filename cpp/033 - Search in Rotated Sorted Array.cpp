class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        else if (target == nums[0])
            return 0;
        
        // var
        int mid = - 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                mid = i;
                break;
            }
        }
        
        if (mid == -1) {
            return _search(0, nums.size() - 1, nums, target);
        }
                
        return target > nums[0] ? _search(0, mid - 1, nums, target) : _search(mid, nums.size() - 1, nums, target);
    }
    
    int _search(int left, int right, vector<int> nums, int target) {
        while (left <= right) {
            // var
            int mid = (left + right) / 2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};