/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* ret = NULL;
    bool appear[100001];
    bool duplicate[100001];
    
    *returnSize = 0;
    memset(&appear, 0, sizeof(appear));
    memset(&duplicate, 0, sizeof(duplicate));
    for (int i = 0; i < numsSize; i++) {
        if (appear[nums[i]] == true) {
            duplicate[nums[i]] = true;
            *returnSize = *returnSize + 1;
        }
        appear[nums[i]] = true;
    }
    
    ret = malloc((*returnSize) * sizeof(int));
    for (int i = 0, j = 0; i < numsSize, j < *returnSize; i++) {
        if (duplicate[i] == true) {
            ret[j] = i;
            j++;
        }
    }
    
    return ret;
}