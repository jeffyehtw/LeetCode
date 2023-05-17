class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int cnt = 1;
        vector<bool> occur(1001, false);

        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] == arr[i]) {
                cnt++;
            } else {
                if (occur[cnt]) {
                    return false;
                } else {
                    occur[cnt] = true;
                }
                cnt = 1;
            }
        }
        return (occur[cnt] == true) ? false : true;
    }
};
