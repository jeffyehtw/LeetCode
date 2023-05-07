class Solution {
private:
    void bubble(vector<int>& height) {
        while (true) {
            bool stop = true;

            for (int i = 1; i < height.size(); i++) {
                if (height[i - 1] > height[i]) {
                    swap(height[i - 1], height[i]);
                    stop = false;
                }
            }

            if (stop) {
                break;
            }
        }
    }
public:
    int heightChecker(vector<int>& heights) {
        int cnt = 0;
        vector<int> sorted(heights.begin(), heights.end());
        
        bubble(sorted);
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sorted[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};
