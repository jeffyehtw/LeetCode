class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ret = 1;
        vector<int> previous(arr.size(), -1);
        unordered_map<int, int> index;

        for (int i = 0; i < arr.size(); i++) {
            if (index.find(arr[i] - difference) != index.end()) {
                previous[i] = index[arr[i] - difference];
            }
            index[arr[i]] = i;
        }
        for (int i = arr.size() - 1; i > -1; i--) {
            int cnt = 1;
            int next = previous[i];

            while (next > -1) {
                cnt++;
                next = previous[next];
            }
            
            ret = max(ret, cnt);
        }

        return ret;
    }
};
