double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0;
    int j = 0;
    int index = 0;
    int len = nums1Size + nums2Size;
    int *arr = malloc(len * sizeof(int));
    double ret = 0;
    
    memset(arr, 0, len * sizeof(int));
    
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] >= nums2[j]) {
            arr[index] = nums2[j];
            index++;
            j++;
        }
        else {
            arr[index] = nums1[i];
            index++;
            i++;
        }
    }
    
    if (i < nums1Size) {
        memcpy(arr + index, nums1 + i, (len - index) * sizeof(int));
    }
    else if (j < nums2Size) {
        memcpy(arr + index, nums2 + j, (len - index) * sizeof(int));
    }
    
    ret = (len & 1) ? arr[len >> 1] : ((double)arr[(len >> 1) - 1] + arr[len >> 1]) / 2;
    free(arr);
    
    return ret;
}