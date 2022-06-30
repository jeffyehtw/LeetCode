class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 0)
            return 0;
            
        // var
        int sum = 0;
        int current = 0;
        int previous = 0;
        int n = A.size();
        
        // init
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            previous += A[i] * i;
        }
        
        int result = previous;
        for (int i = 1; i < A.size(); i++) {
            current = sum - n * A[n - i] + previous;
            previous = current;
            result = max(result, current);
        }
        
        return result;
    }
};