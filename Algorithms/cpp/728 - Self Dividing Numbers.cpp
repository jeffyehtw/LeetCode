class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        // var
        vector<int> r;
        
        while (left <= right) {
            // var
            int n = left;
            bool valid = true;
            
            while (n) {
                if (n % 10 == 0 || left % (n % 10) != 0) {
                    valid = false;
                    break;
                }
                n /= 10;
            }
            
            if (valid)
                r.push_back(left);
            
            left++;
        }
        return r;
    }
};
