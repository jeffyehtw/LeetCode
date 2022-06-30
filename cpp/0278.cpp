// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // var
        int left = 0;
        int right = n;
        
        while (left <= right) {
            // var
            int mid = (right - left) / 2 + left;
            
            if (!isBadVersion(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};