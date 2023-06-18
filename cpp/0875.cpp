class Solution {
private:
    int hours(vector<int>& piles, long long val) {
        long long ret = 0;

        for (int i = 0; i < piles.size(); i++) {
            ret += piles[i] / val;
            if (piles[i] % val > 0) {
                ret++;
            }
        }

        return ret;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        unsigned int left = 1;
        unsigned int right = 1;
        unordered_map<unsigned int, unsigned int> umap;

        for (int i = 0; i < piles.size(); i++) {
            right = max(right, (unsigned int)piles[i]);
        }

        while (left <= right) {
            unsigned int mid = (left + right) / 2;

            umap[mid] = hours(piles, mid);
            if (umap[mid] == h) {
                right = mid - 1;
            } else if (umap[mid] > h) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};
