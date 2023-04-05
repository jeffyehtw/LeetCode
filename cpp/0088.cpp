class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> nums3(nums1.begin(), nums1.begin() + m);

        while (j < n && k < m) {
            if (nums2[j] < nums3[k]) {
                nums1[i] = nums2[j];
                j++;
            } else {
                nums1[i] = nums3[k];
                k++;
            }
            i++;
        }
        while (j < n) {
            nums1[i] = nums2[j];
            j++;
            i++;
        }
        while (k < m) {
            nums1[i] = nums3[k];
            k++;
            i++;
        }
    }
};
