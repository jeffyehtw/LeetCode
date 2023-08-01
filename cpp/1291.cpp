class Solution {
private:
    double num = 123456789;
    double generate(int start, int len) {
        int ret = num;

        if (start > 1) {
            ret %= int(pow(10, 10 - start));
        }
        ret /= pow(10, 10 - start - len);

        return ret;
    }
    int length(int val) {
        int ret = 0;

        while (val > 0) {
            val /= 10;
            ret++;
        }

        return ret;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        int len = length(low);
        bool end = false;
        vector<int> ret;

        for (int i = len; (i < 10) && !end; i++) {
            for (int j = 1; j <= 9 - i + 1; j++) {
                int val = generate(j, i);
                if (val < low) {
                    continue;
                } else if (val > high) {
                    end = true;
                    break;
                }
                ret.push_back(val);
            }
        }

        return ret;
    }
};
