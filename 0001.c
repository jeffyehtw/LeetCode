/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int compare(const void* p1, const void* p2) {
    int v1 = *((int*)p1);
    int v2 = *((int*)p2);
    
    if (v1 == v2) {
        return 0;
    } 
    else if (v1 > v2) {
        return 1;
    }
    else {
        return -1;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int left = 0;
    int right = numsSize - 1;
    int* sorted = malloc(numsSize * sizeof(int));
    int* ret = malloc(2 * sizeof(int));
    
    *returnSize = 2;
    memcpy(sorted, nums, numsSize *sizeof(int));
    memset(ret, 0, sizeof(ret));
    qsort(sorted, numsSize, sizeof(int), compare);
    
    while (left < right) {
        int sum = sorted[left] + sorted[right];
        if (sum == target) {
            break;
        }
        else if (sum > target) {
            right--;
        }
        else {
            left++;
        }
    }
    
    for (int i = 0, j = 0; i < numsSize && j < 2; i++) {
        if (sorted[left] == nums[i]) {
            ret[j] = i;
            j++;
        } 
        else if (sorted[right] == nums[i]) {
            ret[j] = i;
            j++;
        }
    }
    return ret;    
}