class Solution {
private:
    int distance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret;
        priority_queue<vector<int>> pq;

        for (int i = 0; i < points.size(); i++) {
            pq.push({ 
                distance(points[i]), 
                points[i][0], 
                points[i][1]
            });
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            ret.push_back({ pq.top()[1], pq.top()[2] });
            pq.pop();
        }

        return ret;
    }
};
