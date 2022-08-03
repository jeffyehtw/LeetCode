void swap(int* p1, int* p2) {
    int tmp = *p1;           
    *p1 = *p2;               
    *p2 = tmp;               
}                            

void moveZeroes(int* nums, int numsSize) {
    int count = 0;
    
    for (int i = 0; i < numsSize;) {
        if (nums[i] == 0) {
            count++;
            i++;
        }
        else {
            swap(&nums[i - count], &nums[i]);
            i = i - count + 1;
            count = 0;
        }
    }
}