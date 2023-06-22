class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        unsigned int cur = 0;
        vector<int> ret;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> jobs;

        for (int i = 0; i < tasks.size(); i++) {
            pq.push({ tasks[i][0], tasks[i][1], i });
        }
        jobs.push({ pq.top()[1], pq.top()[2] });
        cur = pq.top()[0];
        pq.pop();

        while (!jobs.empty()) {
            ret.push_back(jobs.top()[1]);
            cur += jobs.top()[0];
            jobs.pop();
            while (!pq.empty() && cur >= pq.top()[0]) {
                jobs.push({ pq.top()[1], pq.top()[2] });
                pq.pop();
            }
            if (!pq.empty() && jobs.empty()) {
                cur = pq.top()[0];
                jobs.push({ pq.top()[1], pq.top()[2] });
                pq.pop();
            }
        }

        return ret;
    }
};
