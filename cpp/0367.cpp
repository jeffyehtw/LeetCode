class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long left = 1;
        unsigned long right = num / 2 + 1;

        while (left < right) {
            unsigned long middle = (left + right) / 2;

            if (num == middle * middle) {
                return true;
            } else if (num > middle * middle) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return (num == left * left);
    }
};
