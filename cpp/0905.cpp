class Solution {
private:
    vector<int> tmp;
    void merge(vector<int>& nums, int left, int mid, int right) {
        for (int i = left; i <= right; i++) {
            tmp[i] = nums[i];
        }
        for (int i = left, j = left, k = mid + 1; i <= right; i++) {
            if (j == mid + 1) {
                nums[i] = tmp[k];
                k++;
            } else if (k == right + 1) {
                nums[i] = tmp[j];
                j++;
            } else if (tmp[j] % 2 == tmp[k] % 2) {
                if (tmp[j] > tmp[k]) {
                    nums[i] = tmp[k];
                    k++;
                } else {
                    nums[i] = tmp[j];
                    j++;
                }
            } else if (tmp[j] % 2 == 0) {
                nums[i] = tmp[j];
                j++;
            } else {
                nums[i] = tmp[k];
                k++;
            }
        }
    }
    void sort(vector<int>& nums, int left, int right) {
        int mid = (left + right) >> 1;
        
        if (left == right) {
            return;
        }
        sort(nums, left, mid);
        sort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        tmp = vector<int>(nums.size(), 0);
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
