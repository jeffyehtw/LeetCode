bool compare(void* p1, void* p2) {
    return *(int*)p1 > *(int*)p2;
}

int thirdMax(int* nums, int numsSize) {
    int* distinct = NULL;
    int len = 1;
    int ret;
    
    if (numsSize == 1) {
        return nums[0];
    }
        
    qsort(nums, numsSize, sizeof(int), compare);
    
    distinct = malloc(numsSize * sizeof(int));
    distinct[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] != nums[i]) {
            distinct[len] = nums[i];
            len++;
        }
    }
    
    ret = (len >= 3) ? distinct[len -3] : distinct[len - 1];
    free(distinct);
    
    return ret;
}