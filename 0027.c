static void swap(int* p1, int* p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int removeElement(int* nums, int numsSize, int val){
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        if (nums[left] == val) {
            while (left <= right) {
                if (nums[right] == val) {
                    right--;
                }
                else {
                    swap(&nums[left], &nums[right]);
                    left++;
                    right--;
                    break;
                }
            }
        }
        else {
            left++;
        }
    }
    
    return right + 1;
}