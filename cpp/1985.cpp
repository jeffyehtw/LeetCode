class Solution {
private:
    vector<string> tmp;
    void merge(vector<string>& nums, int left, int mid, int right) {
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
            } else if (tmp[j].length() < tmp[k].length()) {
                nums[i] = tmp[j];
                j++;
            } else if (tmp[j].length() > tmp[k].length()) {
                nums[i] = tmp[k];
                k++;
            } else {
                if (tmp[j] + tmp[k] < tmp[k] + tmp[j]) {
                    nums[i] = tmp[j];
                    j++;
                } else {
                    nums[i] = tmp[k];
                    k++;
                }
            }
        }
    }
    void sort(vector<string>& nums, int left, int right) {
        int mid = (left + right) >> 1;

        if (left == right) {
            return;
        }
        sort(nums, left, mid);
        sort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        tmp = nums;
        sort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
};
