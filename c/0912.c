void swap(int* p1, int* p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int partition(int* nums, int left, int right) {
    int i;
    int j;
    int n;
    int pivot;
    
    srand((unsigned)time(NULL));
    n = rand() % (right - left) + 1;
    swap(&nums[left + n], &nums[right]);
    
    i = left;
    j = left;
    pivot = nums[right];
    for (; j < right; j++) {
        if (nums[j] <= pivot) {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }
    
    swap(&nums[i], &nums[right]);
    
    return i;
}

void quick_sort(int* nums, int left, int right) { 
    if (left >= right)
        return;
    int middle = partition(nums, left, right);
    quick_sort(nums, left, middle - 1);
    quick_sort(nums, middle + 1, right);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int index = 1;
    int* ret = malloc(numsSize * sizeof(int));
    
    memcpy(ret, nums, numsSize * sizeof(int));
    *returnSize = numsSize;
    
    if (numsSize <= 1) {
        return ret;
    }
    
    quick_sort(ret, 0, numsSize - 1);
    
    return ret;
}