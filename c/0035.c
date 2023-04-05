int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int middle;
    
    if (target <= nums[left]) {
        return 0;
    }
    else if (target > nums[right]) {
        return right + 1;
    }
    
    middle = (left + right) >> 1;
    while (left < right) {
        if (target == nums[middle]) {
            return middle;
        }
        else if (target > nums[middle]) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
        middle = (left + right) >> 1;
    }
    
    return target > nums[middle] ? middle + 1 : middle;
}