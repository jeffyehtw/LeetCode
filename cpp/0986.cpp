class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size();
        int n = secondList.size();
        pair<int, int> idx({ 0, 0 });
        vector<vector<int>> ret;

        while ((idx.first < m) && (idx.second < n)) {
            if (firstList[idx.first][1] < secondList[idx.second][0]) {
                idx.first++;
            } else if (firstList[idx.first][0] > secondList[idx.second][1]) {
                idx.second++;
            } else {
                int start = max(
                    firstList[idx.first][0],
                    secondList[idx.second][0]
                );
                int end = min(
                    firstList[idx.first][1],
                    secondList[idx.second][1]
                );
                if (firstList[idx.first][1] < secondList[idx.second][1]) {
                    idx.first++;
                } else {
                    idx.second++;
                }
                ret.push_back({ start, end });
            }
        }

        return ret;
    }
};
