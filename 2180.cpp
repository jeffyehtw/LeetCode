class Solution {
private:
    int sum(int n) {
        int ret = 0;

        while (n > 0) {
            ret += n % 10;
            n /= 10;
        }
        return ret;
    }
public:
    int countEven(int num) {
        int ret = 0;

        for (int i = 2; i <= num; i++) {
            if (sum(i) % 2 == 0) {
                ret++;
            }
        }

        return ret;
    }
};
