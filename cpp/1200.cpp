class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int min = INT_MAX;
        vector<vector<int>> ret;

        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];

            if (min > diff) {
                ret.clear();
                min = arr[i] - arr[i - 1];
                ret.push_back(vector<int>({ arr[i - 1], arr[i] }));
            } else if (min == diff) {
                ret.push_back(vector<int>({ arr[i - 1], arr[i] }));
            }
        }

        return ret;
    }
};
