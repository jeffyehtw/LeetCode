// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        // var
        int left = 1;
        int right = n;
        
        while (1) {
            // var
            int middle = (right - left) / 2 + left;
            int result = guess(middle);
            
            if (result == 0)
                return middle;
            else if (result == 1)
                left = middle + 1;
            else
                right = middle - 1;
        }
    }
};