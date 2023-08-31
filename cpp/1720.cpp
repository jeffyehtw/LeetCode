class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> ret(n + 1, first);

        for (int i = 1; i < n + 1; i++) {
            ret[i] = encoded[i - 1] ^ ret[i - 1];
        }

        return ret;
    }
};
