/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* arr = NULL;
    int* ret = NULL;
    int cnt = 0;
    int index = 0;
    
    arr = malloc(numsSize * sizeof(int));
    for (int i = 1; i <= numsSize; i++) {
        arr[i - 1] = i;
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (arr[nums[i] - 1] == nums[i]) {
            cnt++;
        }
        arr[nums[i] - 1] = -1;
    }
    
    *returnSize = numsSize - cnt;
    
    ret = malloc(cnt * sizeof(int));
    for (int i = 0, j = 0; i < numsSize && j < *returnSize; i++) {
        if (arr[i] != -1) {
            ret[j] = arr[i];
            j++;
        }
    }
    
    free(arr);
    
    return ret;
}