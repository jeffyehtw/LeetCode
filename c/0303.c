typedef struct {
    int* arr;
    int size;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* ret = malloc(sizeof(NumArray));
    
    ret->arr = malloc(numsSize * sizeof(int));
    memcpy(ret->arr, nums, numsSize * sizeof(int));
    ret->size = numsSize;
    
    return ret;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int ret = 0;
    for (int i = left; i < obj->size && i <= right; i++) {
        ret += obj->arr[i];
    }
    return ret;
}

void numArrayFree(NumArray* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/