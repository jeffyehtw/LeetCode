class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> window;
        vector<int> ret;
        int min = INT_MAX;
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += abs(arr[i] - x);
            window.push_back(arr[i]);
        }

        min = sum;
        ret.assign(window.begin(), window.end());

        for (int i = k, j = 0; i < arr.size(); i++, j++) {
            sum += abs(arr[i] - x);
            sum -= abs(arr[j] - x);

            window.push_back(arr[i]);
            window.erase(window.begin());

            if (sum < min) {
                min = sum;
                ret.assign(window.begin(), window.end());
            }
        }

        return ret;
    }
};