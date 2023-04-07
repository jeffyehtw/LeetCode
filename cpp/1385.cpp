class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ret = 0;

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        for (int i = 0; i < arr1.size(); i++) {
            int previous = abs(arr1[i] - arr2[0]);

            if (previous <= d) {
                ret++;
                continue;
            }
            for (int j = 1; j < arr2.size(); j++) {
                int diff = abs(arr1[i] - arr2[j]);
                if (diff <= d) {
                    ret++;
                    break;
                } else {
                    if (diff > previous) {
                        break;
                    } else {
                        previous = diff;
                    }
                }
            }
        }

        return (arr1.size() - ret);
    }
};
