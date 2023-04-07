class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if ((mid == 0) || (mid == arr.size() - 1)) {
                break;
            }

            if ((arr[mid - 1] < arr[mid]) 
                && (arr[mid] > arr[mid + 1])) {
                return mid;
            } else if ((arr[mid - 1] > arr[mid]) 
                && (arr[mid] > arr[mid + 1])) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return (left == 0) ? 1 : arr.size() - 1;
    }
};
