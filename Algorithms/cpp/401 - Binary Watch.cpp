class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        // var
        vector<string> hours[5];
        vector<string> mins[7];
        vector<string> result;
        
        // init
        for (int i = 0; i < 12; i++)
            hours[count_bits(i)].push_back(format(to_string(i), 1));
        for (int i = 0; i < 60; i++)
            mins[count_bits(i)].push_back(format(to_string(i), 2));
        
        // run
        for (int i = 0; i <= min(4, num); i++) {
            for (int j = 0; j < hours[i].size(); j++) {
                // out of range
                if (num - i < 0 || num - i > 6)
                    continue;
                // add
                for (int k = 0; k < mins[num - i].size(); k++)
                    result.push_back(hours[i][j] + ":" + mins[num - i][k]);
            }
        }
        return result;
    }
    
    int count_bits(int num) {
        // var
        int count = 0;
        while (num) {
            count += num % 2;
            num >>= 1;
        }
        return count;
    }
    
    string format(string min, int len) {
        while (min.length() < len)
            min = '0' + min;
        return min;
    }
};