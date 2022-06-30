void static swap(int* p1, int* p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int removeDuplicates(int* nums, int numsSize){
    int ret = 1;
    
    if (numsSize == 1) {
        return ret;
    }
    
    for (; ret < numsSize; ret++) {
        int i = ret;
        int found = false;
        while (i < numsSize) {
            if (nums[i] - nums[ret - 1] > 0) {
                found = true;
                break;
            }
            i++;
        }
        if (found == true) {
            swap(&nums[ret], &nums[i]);
        }
        else {
            break;
        }
    }
    if (ret == numsSize - 1 && nums[ret] > nums[ret - 1]) {
        ret++;
    }
    
    return ret;
}