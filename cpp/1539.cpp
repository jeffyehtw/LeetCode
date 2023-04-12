class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 0;

        for (int i = 1, j = 0; i < INT_MAX; i++) {
            if (j >= arr.size()) {
                cnt++;
            } else {
                if (arr[j] != i) {
                    cnt++;
                } else {
                    j++;
                }
            }
            if (cnt == k) {
                return i;
            }
        }

        return -1;
    }
};
