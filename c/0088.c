void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* arr = malloc(m * sizeof(int));
    int i = 0;
    int j = 0;
    
    memcpy(arr, nums1, m * sizeof(int));
    
    for (int index = 0; index < m + n; index++) {
        if (i < m && j < n) {
            if (arr[i] < nums2[j]) {
                nums1[index] = arr[i];
                i++;
            }
            else {
                nums1[index] = nums2[j];
                j++;
            }
        }
        else if (i >= m) {
            nums1[index] = nums2[j];
            j++;
        }
        else {
            nums1[index] = arr[i];
            i++;
        }
    }
    
    free(arr);
}