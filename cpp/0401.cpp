#define HALF_DAY 720

class Solution {
private:
    int count(unsigned int hour, unsigned int min) {
        int ret = 0;

        while (hour > 0) {
            ret += (hour & 1);
            hour >>= 1;
        }
        while (min > 0) {
            ret += (min & 1);
            min >>= 1;
        }

        return ret;
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        unsigned int hour = 0;
        unsigned int min = 0;
        unsigned int sec = 0;
        vector<string> ret;
        
        if (turnedOn == 0) {
            ret.push_back("0:00");
            return ret;
        }

        while (hour * 60 + min < HALF_DAY) {
            hour += min / 60;
            min %= 60;

            if (count(hour, min) == turnedOn) {
                string h = to_string(hour);
                string m = to_string(min);

                if (m.length() < 2) {
                    m = "0" + m;
                }
                ret.push_back(h + ":" + m);
            }
            min++;
        }

        return ret;
    }
};
