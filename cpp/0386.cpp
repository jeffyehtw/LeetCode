class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        recursive(1, n);
        
        return result;
    }
    
    void recursive(int current, int n) {
        if (current > n)
            return;
        
        result.push_back(current);    
        recursive(current * 10, n);
        
        if (current % 10 != 9)
            recursive(current + 1, n);
    }
    
    // var
    vector<int> result;
};