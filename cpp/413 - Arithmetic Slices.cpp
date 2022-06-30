class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)
            return 0;
        
        // var
        int result = 0;
        
        for (int i = 0; i < A.size() - 2; ) {
            // var
            bool found = false;
            int diff = A[i + 1] - A[i];
            
            for (int j = i + 1; j < A.size(); j++) {
                if (A[j + 1] - A[j] != diff || j == A.size() - 1) {
                    // var
                    int len = j - i + 1;
                    
                    if (len >= 2) {
                        result += ((len - 2) + 1) * (len - 2) / 2;
                        i = j;
                        found = true;
                    }
                    break;
                }
            }
            i += !found;
        }
        return result;
    }
};