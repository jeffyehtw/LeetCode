class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                
                if (pq.size() < k) {
                    pq.push({ nums1[i] + nums2[j], nums1[i] });
                } else if (sum < pq.top().first) {
                    pq.pop();
                    pq.push({ nums1[i] + nums2[j], nums1[i] });
                } else {
                    break;
                }
            }
        }

        while (!pq.empty() && (k > 0)) {
            ret.push_back({
                pq.top().second,
                pq.top().first - pq.top().second,
            });
            pq.pop();
        }

        return ret;
    }
};
