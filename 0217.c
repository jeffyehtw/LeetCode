bool compare(void* p1, void* p2) {
    return *(int*)p1 > *(int*)p2;
}

bool containsDuplicate(int* nums, int numsSize) {    
    qsort(nums, numsSize, sizeof(int), compare);
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        } 
    }
    
    return false;
}