class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ret(length, 0);
        vector<int> prediff(length + 1, 0);

        for (int i = 0; i < updates.size(); i++) {
            prediff[updates[i][0]] += updates[i][2];
            prediff[updates[i][1] + 1] -= updates[i][2];
        }
        ret[0] = prediff[0];
        for (int i = 1; i < ret.size(); i++) {
            ret[i] = ret[i - 1] + prediff[i];
        }

        return ret;
    }
};
