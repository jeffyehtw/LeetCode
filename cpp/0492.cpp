class Solution {
public:
    vector<int> constructRectangle(int area) {
        // var
        vector<int> result;
        int min_diff = INT_MAX;
        
        for (int i = 1; i < sqrt(area) + 1; i++) {
            if (area % i == 0) {
                // var
                int L = area / i;
                int W = i;
                
                if (L < W)
                    swap(L, W);
                
                if (min_diff < L - W) {
                    continue;
                }
                else {
                    min_diff = L - W;
                    result = vector<int>{L, W};
                }
            }
        }
        
        return result;
    }
};