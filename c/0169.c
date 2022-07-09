bool compare(void* p1, void* p2) {
    return *(int*)p1 > *(int*)p2;
}

int majorityElement(int* nums, int numsSize) {
    int ret;
    int max;
    int cur;
    int cnt;
    
    qsort(nums, numsSize, sizeof(int), compare);
    ret = nums[0];
    cur = nums[0];
    cnt = 1;
    max = 1;    
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == cur) {
            cnt++;
        }
        else {
            cur = nums[i];
            cnt = 1;
        }
        if (cnt > max) {
            ret = cur;
            max = cnt;
        }
    }
    
    return ret;
}