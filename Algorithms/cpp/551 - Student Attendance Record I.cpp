class Solution {
public:
    bool checkRecord(string s) {
        // var
        bool absented = s[0] == 'A';
        int late = s[0] == 'L';
        
        for (int i = 1; i < s.length(); i++) {
            // late
            if (s[i] == 'L') {
                late++;
                if (late == 3)
                    return false;
            }
            else {
                late = 0;
            }
            
            // absent
            if (s[i] == 'A') {
                if (absented)
                    return false;
                absented = true;
            }
        }
        return true;
    }
};